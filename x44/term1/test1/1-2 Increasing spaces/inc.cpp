/*
Eugene Auduchinok (c) 2013

Test 1.1.2
Increasing Spaces
*/

#include <iostream>
#include <cctype>
#include "inc.h"

queue::Queue *createWordsQueue()
{
	queue::Queue *words = queue::createQueue();

	bool readingAWord = false;
	char *word = nullptr;
	int wordLength = 0;
	char c = 0;

	do
	{
		c = getchar();

		if (isspace(c) && !readingAWord)
		{
			continue;
		}

		if (isspace(c) && readingAWord)
		{
			word[wordLength] = 0;
			queue::push(words, word);

			word = nullptr;
			readingAWord = false;

			continue;
		}

		if (readingAWord)
		{
			word[wordLength] = c;
			wordLength++;
		}
		else
		{
			word = new char[20];
			word[0] = c;
			wordLength = 1;

			readingAWord = true;
		}

	} while (c != '\n');

	return words;
}