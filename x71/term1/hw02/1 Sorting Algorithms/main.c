/*
Eugene Auduchinok (c) 2013

Homework 1.02.01
Sorting algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qsort.h"
#include "heapsort.h"
#include "bubble.h"
#include "util.h"

int copyArray(int *src, int *dest, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}

void printArray(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void mirrorArray(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n / 2; i++)
	{
		swap(&a[i], &a[n - 1 - i]);
	}
}

int main()
{
	printf("Sorting algorithms\n");

	srand(time(NULL));

	int i = 0;
	int arrayLength = 10;

	for (arrayLength = 10; arrayLength < 1000000; arrayLength *= 100)
	{
		int *randomArray = (int *) malloc(sizeof(int) * arrayLength);
		for (i = 0; i < arrayLength; i++)
		{
			randomArray[i] = rand() % 20;
		}

		int **sortedArrays = (int **) malloc(sizeof(int) * 3);
		for (i = 0; i < 3; i++)
		{
			sortedArrays[i] = (int *) malloc(sizeof(int) * arrayLength);
			copyArray(randomArray, sortedArrays[i], arrayLength);
		}

		clock_t t = clock();
		heapSort(sortedArrays[0], arrayLength);
		printf("Heapsort (%d) (random): %f\n", arrayLength, (clock() - t) / (double) CLOCKS_PER_SEC);

		mirrorArray(sortedArrays[0], arrayLength);
		t = clock();
		heapSort(sortedArrays[0], arrayLength);
		printf("Heapsort (%d) (backwise): %f\n", arrayLength, (clock() - t) / (double) CLOCKS_PER_SEC);

		t = clock();
		qSort(sortedArrays[1], arrayLength);
		printf("Quicksort (%d) (random): %f\n", arrayLength, (clock() - t) / (double) CLOCKS_PER_SEC);

		mirrorArray(sortedArrays[1], arrayLength);
		t = clock();
		qSort(sortedArrays[1], arrayLength);
		printf("Quicksort (%d) (backwise): %f\n", arrayLength, (clock() - t) / (double) CLOCKS_PER_SEC);

		t = clock();
		bubbleSort(sortedArrays[2], arrayLength);
		printf("Bubblesort (%d) (random): %f\n", arrayLength, (clock() - t) / (double) CLOCKS_PER_SEC);

		mirrorArray(sortedArrays[2], arrayLength);
		t = clock();
		heapSort(sortedArrays[2], arrayLength);
		printf("Bubblesort (%d) (backwise): %f\n", arrayLength, (clock() - t) / (double) CLOCKS_PER_SEC);

		free(randomArray);
		for (i = 0; i < 3; i++)
		{
			free(sortedArrays[i]);
		}

		printf("\n");
	}
}