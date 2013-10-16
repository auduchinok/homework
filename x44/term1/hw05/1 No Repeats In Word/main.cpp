/*
Eugene Auduchinok (c) 2013

Homework 1.05.01
No Repeats
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

char *RemoveRepeats(char *word)
{
	int wordLength = strlen(word);
	char *result = new char[256];
	int resultLenth = 0;

	for (int i = 0; i < wordLength; i++)
	{
		if (word[i] == 0)
		{
			continue;
		}

		result[resultLenth] = word[i];
		resultLenth++;

		for (int j = i + 1; j < wordLength; j++)
		{
			if (tolower(word[j]) == tolower(word[i]))
			{
				word[j] = 0;
			}
		}
	}

	result[resultLenth] = 0;

	delete[] word;

	return result;
}

void readFile(ifstream &in)
{
	char *word = nullptr;
	int wordLength = 0;
	bool ReadingAWord = false;

	while (!in.eof())
	{
		char c = in.get();
		
		if (isalpha(c))
		{
			if (ReadingAWord)
			{
				word[wordLength] = c;
				wordLength++;
			}
			else
			{
				word = new char[256];
				word[0] = c;
				wordLength = 1;

				ReadingAWord = true;
			}

			continue;
		}

		if (ReadingAWord)
		{	
			word[wordLength] = 0;
			word = RemoveRepeats(word);
			cout << word;
			delete[] word;

			ReadingAWord = false;

			cout << c;
		}
		else
		{
			cout << c;
		}
	}
}

int main(int argc, char **argv)
{
	// Удобно тестить на main.cpp :)
	ifstream in(argv[1]);

	readFile(in);

	in.close();
}