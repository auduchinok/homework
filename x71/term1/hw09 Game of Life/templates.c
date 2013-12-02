/* Eugene Auduchinok (c) 2013

Game of Life v0.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "templates.h"

typedef struct TreeNode
{
	Template *template;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct Tree
{
	TreeNode *root;
} Tree;

void add_template(Template *template);


static Tree templates;

Template *create_template(int width, int height)
{
	Template *result = (Template *) malloc(sizeof(Template));

	result->name = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
	result->width = width;
	result->height = height;
	result->pic_data = (int *) malloc(sizeof(int) * width * height);
	result->picture = (int **) malloc(sizeof(int *) * height);

	memset(result->pic_data, 0, sizeof(int) * height * width);

	int i = 0;
	for (i = 0; i < height; i++)
	{
		result->picture[i] = &result->pic_data[i * width];
	}

	return result;
}

void read_templates()
{
	FILE *in = fopen("templates.txt", "r");

	if (!in)
	{
		printf("Can't find \"templates.txt\" file.\n");
		exit(2);
	}

	while (!feof(in))
	{
		char template_name[MAX_WORD_LENGTH];
		fscanf(in, "%s", template_name);
	
		int width = 0;
		int height = 0;
		fscanf(in, "%d %d", &width, &height);

		Template *to_add = create_template(width, height);

		strcpy(to_add->name, template_name);

		char *line = (char *) malloc(sizeof(char) * (width + 1));

		int i = 0;
		int j = 0;

		for (i = 0; i < height; i++)
		{
			fscanf(in, "%s", line);

			for (j = 0; j < width; j++)
			{
				if (line[j] == '#')
				{
					to_add->picture[i][j] = 1;
				}
			}
		}

		add_template(to_add);
		free(line);
	}

	fclose(in);
}

Template *get_template(char *template_name)
{
	TreeNode *node = templates.root;

	while (node != NULL && strcmp(node->template->name, template_name))
	{
		if (strcmp(node->template->name, template_name) > 0)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	if (node == NULL)
	{
		printf("Can't find template \"%s\".\n", template_name);
		return NULL;
	}

	Template *template = node->template;
	Template *result = create_template(template->width, template->height);

	strcpy(result->name, template->name);
	memcpy(result->pic_data, template->pic_data, 
		sizeof(int) * template->height * template->width);

	return result;
}

TreeNode *create_node(Template *template)
{
	TreeNode *result = (TreeNode *) malloc(sizeof(TreeNode));
	result->template = template;

	result->left = NULL;
	result->right = NULL;

	return result;
}

void add_template(Template *template)
{
	TreeNode *node = templates.root;
	TreeNode *parent = NULL;
	int went_left = 0;

	while (node != NULL)
	{
		 parent = node;

		if (strcmp(node->template->name, template->name) > 0)
		{
			node = node->left;
			went_left = 1;
		}
		else
		{
			node = node->right;
			went_left = 0;
		}
	}

	node = create_node(template);

	if (parent == NULL)
	{
		templates.root = node;
		return;
	}

	if (went_left)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
}

void delete_template(Template *t)
{
	free(t->name);
	free(t->pic_data);
	free(t->picture);
}

void delete_node(TreeNode *node)
{
	if (node->left)
	{
		delete_node(node->left);
	}

	if (node->right)
	{
		delete_node(node->right);
	}

	delete_template(node->template);
	free(node);
}

void delete_all_templates()
{
	if (templates.root)
	{
		delete_node(templates.root);
	}
}