#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

// returns days
int parseDate(char *str)
{
	if (strlen(str) != 10)
	{
		return 0;
	}

	if (str[2] != '.' || str[5] != '.')
	{
		return 0;
	}

	for (int i = 0; i < 2; i++)
	{
		if (!isdigit(str[i]) || !isdigit(str[3 + i]))
		{
			return 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(str[6 + i]))
		{
			return 0;
		}
	}

	/*
	Здесь можно было красиво все разбить на две функции,
	аккуратно разбить на день/месяц/год,
	но времени оставалось всего ничего, поэтому сделал не очень хорошо.
	*/

	char dayStr[3] = {0};
	char monthStr[3] = {0};
	char yearStr[5] = {0};

	for (int i = 0; i < 2; i++)
	{
		dayStr[i] = str[i];
		monthStr[i] = str[3 + i];
	}
	dayStr[2] = 0;
	monthStr[2] = 0;

	for (int i = 0; i < 4; i++)
	{
		yearStr[i] = str[6 + i];
	}
	yearStr[4] = 0;

	int day = atoi(dayStr);
	int month = atoi(monthStr);
	int year = atoi(yearStr);

	
	if (year < 0)
	{
		return 0;
	}


	if (month < 1 || month > 12)
	{
		return 0;
	}

	if (day < 1 || day > 31) // здесь тоже можно сделать правильную проверку
	{
		return 0;
	}

	return 365 * year + 31 * month + day;
}

int main(int argc, char **argv)
{
	cout << "Min date." << endl;

	ifstream in(argv[1]);
	if (!in)
	{
		cout << "No such file." << endl;
		return 1;
	}

	int minDate = INT_MAX;
	char minDateStr[64] = {0};
	char word[64] = {0};

	while (!in.eof())
	{
		in >> word;
		int date = parseDate(word);

		if (!date)
		{
			continue;
		}

		if (date < minDate)
		{
			minDate = date;
			strcpy(minDateStr, word);
		}
	}
	in.close();

	if (minDate == INT_MAX)
	{
		cout << "No date appears in the file." << endl;
		return 0;
	}

	cout << minDateStr << endl;
}