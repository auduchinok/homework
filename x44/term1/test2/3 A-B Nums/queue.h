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
		int value;
		QueueElement *next;
	};

	struct Queue
	{
		QueueElement *front;
		QueueElement *back;
	};

	Queue *create();
	void deleteQueue(Queue *queue);
	void push(Queue *queue, int value);
	void pop(Queue *queue);
	int front(Queue *queue);
	bool isEmpty(Queue *queue);
};