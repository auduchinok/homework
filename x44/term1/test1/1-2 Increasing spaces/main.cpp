/*
Eugene Auduchinok (c) 2013

Test 1.1.2
Increasing Spaces
*/

#include <iostream>
#include "inc.h"
#include "queue.h"
using namespace std;

void printWithSpaces(queue::Queue *words, int newLength)
{
	int spaces = newLength - words->length;

	int spacesBetween = spaces / (words->words - 1);
	int left = spaces % (words->words - 1);

	for (int i = 0; i < words->words; i++)
	{
		cout << queue::front(words);
		queue::pop(words);

		if (i == words->words - 1)
		{
			break;
		}

		for (int j = 0; j < spacesBetween; j++)
		{
			cout << " ";
		}

		if (i < left)
		{
			cout << " ";
		}
	}

	cout << endl;
}

int main()
{
	cout << "1.2 Increasing Spaces" << endl;

	queue::Queue *words = createWordsQueue();

	int newLength = 0;
	cin >> newLength;

	printWithSpaces(words, newLength);

	queue::deleteQueue(words);	
}