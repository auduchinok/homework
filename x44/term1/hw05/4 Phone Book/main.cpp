/*
Eugene Auduchinok (c) 2014
Hw 144-1.05.04 Phone book
*/

#include <iostream>
#include "data.h"

int main()
{
	std::cout << "Phone book" << std::endl;

	Database db;

	int mode = -1;
	char name[db.nameLength] = {'\0'};
	char number[db.nameLength] = {'\0'};
	char *result = nullptr;

	while (mode != 0)
	{
		std::cout << "---" << std::endl <<
		"1 - add new entry" << std::endl <<
		"2 - find by name" << std::endl <<
		"3 - find by number" << std::endl << 
		"4 - save to the file" << std::endl << 
		"0 - exit" << std::endl;

		std::cout << "your choice: ";
		std::cin >> mode;
		std::cin.ignore(256, '\n');

		switch (mode)
		{
			case 1:
			{
				std::cout << "name: ";
				std::cin.getline(name, db.nameLength);

				std::cout << "number: ";
				std::cin.getline(number, db.nameLength);

				db.addRecord(name, number);

				break;
			}
			case 2:
			{
				std::cout << "name: ";
				std::cin.getline(name, db.nameLength);

				result = db.findByName(name);

				if (result == nullptr)
				{
					std::cout << name << " was not found." << std::endl;
				}
				else
				{
					std::cout << "Found: " << result << std::endl;

					delete[] result;
				}

				break;
			}
			case 3:
			{
				std::cout << "number: ";
				std::cin.getline(number, db.nameLength);

				result = db.findByNumber(number);

				if (result == nullptr)
				{
					std::cout << number << " was not found." << std::endl;
				}
				else
				{
					std::cout << "Found: " << result << std::endl;
					
					delete[] result;

					break;
				}
			}
			case 4:
			{
				db.saveToFile();
			}
		}
	}
}