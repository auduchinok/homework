#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;

void printQueueToFile(queue::Queue *queue, ofstream &out)
{
	while (!queue::isEmpty(queue))
	{
		out << queue::front(queue) << " ";
		queue::pop(queue);
	}
}

bool checkFileCorrect(ifstream &in)
{
	if (!in)
	{
		cout << "No such file." << endl;
		return false;
	}

	in.seekg(0, in.end);
	int fileLength = in.tellg();
	if (fileLength == 0)
	{
		cout << "The file is empty." << endl;
		return false;
	}
	in.seekg(0, in.beg);

	return true;
}

void writeABfile(int a, int b, ifstream &in)
{
	queue::Queue *lessA = queue::create();
	queue::Queue *betweenAB = queue::create();
	queue::Queue *greaterB = queue::create();

	while (!in.eof())
	{
		int nextNum = 0;

		in >> nextNum;

		if (nextNum < a)
		{
			queue::push(lessA, nextNum);
		}
		else if (nextNum > b)
		{
			queue::push(greaterB, nextNum);
		}
		else
		{
			queue::push(betweenAB, nextNum);
		}
	}
	in.close();

	ofstream out("ab_out.txt");
	printQueueToFile(lessA, out);
	printQueueToFile(betweenAB, out);
	printQueueToFile(greaterB, out);
	out << endl;
	out.close();

	queue::deleteQueue(lessA);
	queue::deleteQueue(betweenAB);
	queue::deleteQueue(greaterB);
}

int main(int argc, char **argv)
{
	cout << "AB-Nums" << endl;

	if (argc < 2)
	{
		cout << "No input file." << endl;
		return 1;
	}

	ifstream in(argv[1]);
	if (!checkFileCorrect(in))
	{
		return 1;
	}

	int a = 0;
	int b = 0;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	writeABfile(a, b, in);

}