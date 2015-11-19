// Eugene Auduchinok, 2015
#include "stdafx.h"

extern "C" int sum(int a, int b);

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 3;
	int b = 4;
	printf("%d + %d = %d\n", a, b, sum(a, b));

    return 0;
}

