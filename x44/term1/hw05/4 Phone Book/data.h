/*
Eugene Auduchinok (c) 2014
Hw 144-1.05.04 Phone book
*/

#pragma once

struct Record
{
	char *name;
	char *number;	
};

class Database
{
private:
	static const int defaultSize = 8;
	Record *data;
	int size;
	int recordsCount;

	void loadFromFile(std::ifstream &file);
	void enlarge();
	char *makeResult(char *found);

public:
	static const int nameLength = 20;
	Database();
	~Database();

	void addRecord(char *name, char *number);
	char *findByName(char *name);
	char *findByNumber(char *number);
	void saveToFile();
};