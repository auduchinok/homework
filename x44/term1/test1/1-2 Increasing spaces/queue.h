/*
Eugene Auduchinok (c) 2013

Test 1.1.2
Increasing Spaces
*/

#pragma once

namespace queue
{
	struct QueueElement
	{
		char *string;
		QueueElement *next;
	};

	struct Queue
	{
		QueueElement *front;
		QueueElement *back;
		int words;
		int length;
	};

	Queue *createQueue();
	void deleteQueue(Queue *queue);
	void push(Queue *queue, char *string);
	void pop(Queue *queue);
	char *front(Queue *queue);
	bool isEmpty(Queue *queue);
};