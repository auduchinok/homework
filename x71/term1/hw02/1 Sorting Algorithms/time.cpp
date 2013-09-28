#include <iostream>
#include <ctime>
using namespace std;

int main()
{	
	clock_t t = clock();
	cout << t << endl;

	clock_t t2 = clock();
	cout << t2 << endl;

	cout << (t2 - t) / (double)CLOCKS_PER_SEC << endl;
}