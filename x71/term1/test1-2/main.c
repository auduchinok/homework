#include <stdio.h>
#include "blackjack.h"

int main(int argc, char **argv)
{
	printf("Blackjack Game\n");

	FILE *pack = fopen(argv[1], "r");
	FILE *moves = fopen(argv[2], "r");

	int score = game(pack, moves);
	printf("score: %d\n", score);
}