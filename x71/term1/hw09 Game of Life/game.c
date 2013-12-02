/* Eugene Auduchinok (c) 2013

Game of Life v0.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "game.h"
#include "templates.h"

// Game variables
static int width;
static int height;
static int **field;
static int *field_data;

static int **field_turn;
static int *field_data_turn;

static const int TIMER_SPEED = 75;
static const int FIELD_START_X = 2;
static const int FIELD_START_Y = 2;

void put_template(char *template_name, int x, int y)
{
	printf("Placing \"%s\" template at (%d, %d)\n", template_name, x, y);
	int i = 0;
	int j = 0;
	Template *t = get_template(template_name);

	if (t->width > width || t->height > height)
	{
		printf("The game field is too small to put the \"%s\" template.\n", template_name);
		delete_data();
		exit(3);
	}

	for (i = 0; i < t->height; i++)
	{
		for (j = 0; j < t->width; j++)
		{
			if (t->picture[i][j])
			{
				field[(y + i) % height][(x + j) % width] = 1;
			}
		}
	}

	delete_template(t);
}

void create_game(char *filename)
{
	FILE *in = fopen(filename, "r");

	if (!in)
	{
		printf("Can't open the file. Quitting.\n");
		exit(1);
	}

	fscanf(in, "%d %d", &width, &height);

	field = (int **) malloc(sizeof(int *) * height);
	field_data = (int *) malloc(sizeof(int) * width * height);

	field_turn = (int **) malloc(sizeof(int *) * height);
	field_data_turn = (int *) malloc(sizeof(int) * width * height);

	int i = 0;

	for (i = 0; i < height; i++)
	{
		field[i] = &field_data[i * width];
		field_turn[i] = &field_data_turn[i * width];
	}

	memset(field_data, 0, sizeof(int) * width * height);

	char template_name[MAX_WORD_LENGTH];
	memset(template_name, 0, sizeof(char) * MAX_WORD_LENGTH);

	int template_x = 0;
	int template_y = 0;

	while (!feof(in))
	{
		fscanf(in, "%s %d %d", template_name, &template_x, &template_y);
		put_template(template_name, template_x, template_y);
	}

	fclose(in);	
}

int neighbors(int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}

			if (field[(row + i + height) % height][(col + j + width) % width])
			{
				count++;
			}
		}
	}
	
	return count;
}

void turn()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (neighbors(i, j) == 3)
			{
				field_turn[i][j] = field[i][j] + 1;;
			}
			else if ((field[i][j] != 0) && (neighbors(i, j) == 2))
			{
				field_turn[i][j] = field[i][j] + 1;
			}
			else
			{
				field_turn[i][j] = 0;
			}
		}
	}

	int **field_swap = field;
	field = field_turn;
	field_turn = field_swap;
}

void print_field()
{
	int i = 0;
	int j = 0;

	

	for (i = 0; i < height; i++)
	{
		move(FIELD_START_Y + i, FIELD_START_X);

		for (j = 0; j < width; j++)
		{
			if (field[i][j] != 0)
			{
				addstr("# ");
			}
			else
			{
				addstr(". ");
			}
		}
	}
}

void start_ncurses()
{
	initscr();
	noecho();
	curs_set(0);
	timeout(TIMER_SPEED); //75
}

void play_game()
{
	start_ncurses();
	
	char title[] = "-= Game of Life =-\n";

	move(0, width - strlen(title) / 2);
	addstr(title);

	int quit_char = 0;
	while (quit_char != 'q')
	{
		quit_char = getch();

		print_field();
		turn();
	}
	
	endwin();
}

void delete_game()
{
	free(field_data);
	free(field);
	free(field_data_turn);
	free(field_turn);
}

void delete_data()
{
	delete_game();
	delete_all_templates();
}