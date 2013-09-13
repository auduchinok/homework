/*
Eugene Auduchinok (c) 2013

Homework 1.01.04
Lucky tickets
*/

#include <iostream>
using namespace std;

int main()
{
	int sum[28] = {0};

	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
			{
				sum[i + j + k]++;
			}

	long long int answer = 0;

	for (int i = 0; i <= 27; i++)
	{
		if (sum[i] == 1)
			answer++;
		else
			answer += sum[i] * (sum[i] - 1);
	}

	cout << answer << endl;
}