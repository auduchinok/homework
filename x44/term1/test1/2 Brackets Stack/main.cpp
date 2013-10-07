#include <iostream>
#include "isCorrectText.h"
using namespace std;

int main()
{
	cout << "2 Brackets Stack" << endl;

	char buffer[128] = {0};

	cout << "string :";
	cin >> buffer;

	if (isCorrect(buffer))
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Not correct." << endl;
	}
}