/*
Eugene Auduchinok (c) 2013

Homework 1.05.01
No Repeats
*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

char *removeNulls(char *src, int length)
{	
	char *result = new char[length];
	int resLength = 0;

	for (int i = 0; i < length; i++)
	{
		if (src[i] != 0)
		{
			result[resLength] = src[i];
			resLength++;
		}
	}
	result[resLength] = 0;
	
	delete[] src;
	return result;
}

char *removeRepeats(char *src, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (!isalpha(src[i]))
		{
			continue;
		}
		
		for (int j = i + 1; !isspace(src[j]); j++)
		{
			if (tolower(src[i]) == tolower(src[j]))
			{
				src[j] = 0;
			}
		}
	}

	return removeNulls(src, length);
}

void printFile(ifstream &in)
{
	in.seekg(0, in.end);
	int fileLength = in.tellg();
	char *buffer = new char[fileLength];
	in.seekg(0, in.beg);

	in.read(buffer, fileLength);
	
	char *text = removeRepeats(buffer, fileLength);

	cout << text << endl;

	delete[] text;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		cout << "No files to open." << endl;
		return 0;
	}

	bool showFileNames = argc - 1 > 1;

	for (int i = 1; i < argc; i++)
	{
		ifstream in(argv[i]);
		if (!in)
		{
			cout << "No such file: " << argv[i] << endl;
			continue;
		}

		if (showFileNames)
		{
			cout << "==> " << argv[i] << " <==" << endl;
		}
		
		printFile(in);
		in.close();
	}
}