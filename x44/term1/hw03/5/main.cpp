/* Eugene Auduchinok (c) 2013

Homework 1.03.05
A Count Game
*/

#include <iostream>
#include "list.h"
using namespace std;
using namespace list;

int main()
{
	cout << "A Count Game" << endl;

	int n = 0;
	int m = 0; 

	cout << "n: ";
	cin >> n;

	cout << "m: ";
	cin >> m;

	List *list = createList();

	for (int i = 0; i < n; i++)
	{
		add(list, i + 1);
	}
	
	removeInTurns(list, m);

	cout << get(list, 0) << endl;

	deleteList(list);
}