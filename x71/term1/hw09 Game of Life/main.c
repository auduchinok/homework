/* Eugene Auduchinok (c) 2013

Game of Life v0.1
*/

#include <stdio.h>
#include "game.h"
#include "templates.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("No config file is specified.\n");
		return 1;
	}

	read_templates();
	create_game(argv[1]);
	
	play_game();

	delete_data();
}
