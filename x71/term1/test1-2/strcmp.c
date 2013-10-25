#include <ctype.h>
#include "strcmp.h"

int strcmpToLower(char *s1, char *s2)
{
	int i = 0;

	for (i = 0; s1[i] != 0 && s2[i] != 0; i++)
		{
			if (tolower(s1[i]) != tolower(s2[i]))
			{
				break;
			}
		}

		if (tolower(s1[i]) == tolower(s2[i]))
		{
			return 0;
		}

		return (tolower(s1[i]) > tolower(s2[i])) ? 1 : -1;
}