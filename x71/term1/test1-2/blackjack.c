#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strcmp.h"
#include "blackjack.h"

int getValue(char *value)
{
	int result = atoi(value);

	if (result != 0)
	{
		return result;
	}

	if (!strcmpToLower(value, "Ace"))
	{
		return 11;
	}

	return 10;
}

int game(FILE *pack, FILE *moves)
{
	char action[32];
	char card[32];

	int sum = 0;
	int red = 0;
	int black = 0;

	char *value = NULL;
	char *suit = NULL;
	char *move = NULL;

	while (!feof(moves))
	{
		fgets(action, 32, moves);

		move = strtok(action, " \n");
		if (strcmpToLower(move, "Take"))
		{
			break;
		}

		fgets(card, 32, pack);

		value = strtok(card, " \n");
		sum += getValue(value);
		if (sum > 21)
		{
			break;
		}

		suit = strtok(NULL, " \n");
		if (!strcmpToLower(suit, "Spades") || !strcmpToLower(suit, "Clubs"))
		{
			black++;
		}
		else
		{
			red++;
		}
	}

	sum = (sum > 21) ? (sum - 21) * 3 : 21 - sum;
	if (!red || !black)
	{
		sum /= 2;
	}

	return sum;
}