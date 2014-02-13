#include <iostream>
#include <fstream>

int *getStudents(std::ifstream &in, int n)
{
	int *students = new int[n];
	for (int i = 0; i < n; i++)
	{
		int current = 0;
		in >> current;

		int copiedFrom = 0;
		in >> copiedFrom;

		students[current - 1] = copiedFrom;
	}

	return students;
}

void findSources(int *students, int n)
{
	for (int i = 0; i < n; i++)
	{
		while (students[i] > 3)
		{
			students[i] = students[students[i] - 1];
		}
	}
}

void printWithSources(int *students, int n)
{
	for (int j = 1; j <= 3; j++)
	{
		std::cout << "Source " << j << ":\n";

		for (int i = 0; i < n; i++)
		{
			if (students[i] == j)
			{
				std::cout << i + 1 << " ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << "To be expelled:\n";

	for (int i = 0; i < n; i++)
	{
		if (students[i] == 0)
		{
			std::cout << i + 1 << " ";
		}
	}

	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "copied: usage: copied <filename>\n";
		return 1;
	}

	std::ifstream in(argv[1]);

	if (!in)
	{
		std::cout << "copied: no such file\n";
		return 2;
	}

	int number = 0;
	in >> number;

	int *students = getStudents(in, number);
	in.close();

	findSources(students, number);
	printWithSources(students, number);

	delete[] students;

	return 0;
}