/*
Eugene Auduchinok (c) 2013

Homework 2.02.07
Bulls & Cows
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int cows(char *secret, char *guess)
{
	int cowsCount = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j != i && secret[i] == guess[j])
				cowsCount++;
		}
	}

	return cowsCount;
}

int bulls(char *secret, char *guess)
{
	int bullsCount = 0;

	for (int i = 0; i < 4; i++)
	{
		if (secret[i] == guess[i])
			bullsCount++;
	}

	return bullsCount;
}

bool isCorrectNum(char *guess)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j != i && guess[i] == guess[j])
			{
				return false;
			}
		}
	}

	return true;
}

bool attempt(const int num, char *secret, char *guess)
{
	cout << endl << "Attempt #" << num << "." << endl;

	cout << "guess: ";
	cin >> guess;	

	while (!isCorrectNum(guess))
	{	
		cout << "Num is incorrect." << endl << "guess: ";
		cin >> guess;
	}

	if (bulls(secret, guess) == 4)
	{
		return true;
	}

	cout << cows(secret, guess) << " cow(s)" << endl;
	cout << bulls(secret, guess) << " bull(s)" << endl;

	return false;

}

bool existsInNum(int num, char *secret)
{
	for (int i = 0; secret[i] != 0; i++)
	{
		if (num + '0' == secret[i])
		{
			return true;
		}
	}

	return false;
}

char *createSecret()
{
	char *secret = new char[4];
	for (int i = 0; i < 4; i++)
	{
		int nextDigit = 0;

		while (nextDigit == 0 || existsInNum(nextDigit, secret))
		{
			nextDigit = rand() % 10;
		}

		secret[i] = nextDigit + '0';
	}

	return secret;
}

void deleteData(char *secret, char *guess)
{
	delete[] secret;
	delete[] guess;
}

void game(const int attempts)
{
	cout << endl;
	cout << "Game started." << endl;
	cout << "Guess the num in " << attempts << " attempts." << endl;

	char *secret = createSecret();
	char *guess = new char[4];

	for (int i = 1; i <= attempts; i++)
	{
		if (attempt(i, secret, guess))
		{
			cout << "You've done it in " << i << " attempts!" << endl;
			deleteData(secret, guess);
			
			return;
		}
	}

	cout << "You lost." << endl;
	deleteData(secret, guess);
}

int main()
{
	cout << "Cows & Bulls." << endl;

	srand(time(NULL));

	int attemptsNum = 7;
	int mode = -1;

	while (mode != 0)
	{	
		cout << endl;
		cout << "1: Play the game." << endl;
		cout << "2: Set number of attempts." << endl;
		cout << "0: Quit." << endl;

		cout << "Your choice: ";
		cin >> mode;

		switch (mode)
		{
			case 1:
			{
				game(attemptsNum);
				
				mode = -1;

				break;
			}
			case 2:
			{
				cout << "Number of attempts: ";
				cin >> attemptsNum;

				mode = -1;

				break;
			}
		}
	}
}