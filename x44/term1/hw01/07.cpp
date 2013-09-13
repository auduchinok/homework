/*
Eugene Auduchinok (c) 2013

Homework 1.01.07
Prime nums
*/

#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cout << "n: ";
	cin >> n;

	bool *nums = new bool[n + 1];

	for (int i = 0; i <= n; i++)
		nums[i] = true;

	nums[0] = false;
	nums[1] = false;

	for (int i = 2; i <= n; i++)
	{
		if (!nums[i])
			continue;

		for (int j = i * 2; j <= n; j += i)
		{
			nums[j] = false;
		}

		cout << i << " ";
	}

	cout << endl;

	delete[] nums;
}