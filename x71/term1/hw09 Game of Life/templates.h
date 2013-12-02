/* Eugene Auduchinok (c) 2013

Game of Life v0.1
*/

#ifndef templates_h
#define templates_h

static const int MAX_WORD_LENGTH = 20;

typedef struct Template
{
	char *name;
	int **picture;
	int *pic_data;
	int width;
	int height;
} Template;

void read_templates();
Template *get_template(char *template_name);
void delete_template(Template *t);
void delete_all_templates();

#endif
