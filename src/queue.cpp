#include <iostream>
#include "queue.h"

// Constructor
Queue::Queue(int capacity)
	: capacity(capacity), frontal(0), rear(-1), filled(0)
{
	queue = new int[capacity];
}

// Destructor
Queue::~Queue()
{
	delete[] queue;
}


void
Queue::enqueue(int data)
{
	if (is_full())
	{
		std::cout << "\n\tOverflow! Program exists...\n";
		exit(EXIT_FAILURE);
	}

	rear = (rear + 1) % capacity;
	queue[rear] = data;
	filled++;
}


int
Queue::dequeue()
{
	if (is_empty())
	{
		std::cout << "\n\tUnderflow! Program exists...\n";
		exit(EXIT_FAILURE);
	}

	int data = queue[frontal];
	std::cout << "\n\t*** Removing: " << data << " ***\n";

	frontal = (frontal + 1) % capacity;
	filled--;

	return data;
}


int
Queue::front()
{
	if (is_empty())
	{
		std::cout << "Underflow! Program exists...\n";
		exit(EXIT_FAILURE);
	}

	return queue[frontal];
}


int
Queue::back()
{
	if (is_empty())
	{
		std::cout << "Underflow! Program exists...\n";
		exit(EXIT_FAILURE);
	}

	return queue[rear];
}


int
Queue::size()
{
	return filled;
}


bool
Queue::is_empty()
{
	return filled == 0;
}


bool
Queue::is_full()
{
	return filled == capacity;
}
