/*
Eugene Auduchinok (c) 2014
Hw 144-1.05.04 Phone book
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "data.h"

Database::Database()
{
	std::ifstream file("data.db");

	if (file.is_open())
	{
		loadFromFile(file);
		return;
	}

	size = defaultSize;
	data = new Record[size];

	for (int i = 0; i < size; i++)
	{
		data[i].name = nullptr;
		data[i].number = nullptr;
	}

	recordsCount = 0;
}

void Database::loadFromFile(std::ifstream &file)
{
	file >> size >> recordsCount;
	file.ignore(256, '\n');

	data = new Record[size];

	for (int i = 0; i < recordsCount; i++)
	{	
		data[i].name = new char[nameLength];
		data[i].number = new char[nameLength];

		file.getline(data[i].name, nameLength);
		file.getline(data[i].number, nameLength);
	}

	file.close();

	for (int i = recordsCount; i < size; i++)
	{
		data[i].name = nullptr;
		data[i].number = nullptr;
	}

	std::cout << recordsCount << " record(s) loaded." << std::endl;
}

Database::~Database()
{
	for (int i = 0; i < recordsCount; i++)
	{
		delete[] data[i].name;
		delete[] data[i].number;
	}

	delete[] data;
}

void Database::saveToFile()
{
	std::ofstream file("data.db");

	file << size << " " << recordsCount << std::endl;

	for (int i = 0; i < recordsCount; i++)
	{
		file << data[i].name << std::endl << data[i].number << std::endl;
	}

	file.close();

	std::cout << "Saved!" << std::endl;
}

void Database::enlarge()
{
	size *= 2;
	Record *newData = new Record[size];

	for (int i = 0; i < recordsCount; i++)
	{
		newData[i].name = data[i].name;
		newData[i].number = data[i].number;
	}

	delete[] data;

	data = newData;
}

void Database::addRecord(char *name, char *number)
{
	int newIndex = recordsCount;

	data[newIndex].name = new char[nameLength];
	data[newIndex].number = new char[nameLength];

	strcpy(data[newIndex].name, name);
	strcpy(data[newIndex].number, number);

	recordsCount++;

	if (recordsCount == size)
	{
		enlarge();
	}
}

char *Database::makeResult(char *found)
{
	char *result = new char[nameLength];
	strcpy(result, found);

	return result;
}

char *Database::findByName(char *name)
{
	for (int i = 0; i < recordsCount; i++)
	{
		if (!strcmp(data[i].name, name))
		{
			return makeResult(data[i].number);
		}
	}

	return nullptr;
}

char *Database::findByNumber(char *number)
{
	for (int i = 0; i < recordsCount; i++)
	{
		if (!strcmp(data[i].number, number))
		{
			return makeResult(data[i].name);
		}
	}

	return nullptr;
}