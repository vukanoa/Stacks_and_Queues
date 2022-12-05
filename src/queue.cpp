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

/* ------------------------------------------------------------------------- */

MyQueue::MyQueue(int capacity)
	: capacity(capacity), filled(0), top_1(-1), top_2(-1)
{
	stack_1 = new int[capacity];
	stack_2 = new int[capacity];
}


MyQueue::~MyQueue()
{
	delete[] stack_1;
	delete[] stack_2;
}


void
MyQueue::enqueue(int data)
{
	if (full())
	{
		std::cout << "\n\tQueue is Full! Unable to insert a new element!\n";
		return;
	}

	if (stack_2_empty())
	{
		// Push a new element to stack_1
		stack_1[++top_1] = data;
		filled++;
	}
	else
	{
		// Pop everything from stack_2 and Push in stack_1
		while (!stack_2_empty())
			stack_1[++top_1] = stack_2[top_2--];

		// Push a new element to stack_1
		stack_1[++top_1] = data;
		filled++;

		/* Stack_2 is now Empty! */
	}
}


void
MyQueue::dequeue()
{
	if (empty())
	{
		std::cout << "Front value doesn't exist! Queue is empty!\n";
		return;
	}

	if (stack_2_empty())
	{
		// Fill stack_2 in reverse order of stack_1
		while (!stack_1_empty())
			stack_2[++top_2] = stack_1[top_1--]; // Pop stack_2, Push stack_1
	}
	// Pop that front element
	top_2--;
	filled--;

	std::cout << "\n\tDEQUEUE\n\n";
}


int
MyQueue::front()
{
	if (empty())
	{
		std::cout << "Front value doesn't exist! Queue is empty!\n";
		exit(-1);
	}

	if (stack_2_empty())
	{
		// Fill stack_2 in reverse order of stack_1
		while (!stack_1_empty())
			stack_2[++top_2] = stack_1[top_1--]; // Pop stack_2, Push stack_1
	}

	return stack_2[top_2];
}


int
MyQueue::back()
{
	if (empty())
	{
		std::cout << "Front value doesn't exist! Queue is empty!\n";
		exit(-1);
	}

	if (stack_1_empty())
	{
		while (!stack_2_empty())
			stack_1[++top_1] = stack_2[top_2--];
	}

	return stack_1[top_1];
}


int
MyQueue::size()
{
	return filled;
}


bool
MyQueue::empty()
{
	return filled == 0;
}


bool
MyQueue::full()
{
	return filled == capacity;
}


void
MyQueue::print_queue()
{
	if (empty())
	{
		std::cout << "\n\tQueue: []\n";
		return;
	}

	// Fill stack_2 in reverse order of stack_1
	while (!stack_1_empty())
		stack_2[++top_2] = stack_1[top_1--]; // Pop stack_2, Push stack_1
	
	bool first = true;
	std::cout << "\n\tQueue: [";
	while (!stack_2_empty())
	{
		if (!first)
			std::cout << ", ";

		stack_1[++top_1] = stack_2[top_2--];
		std::cout << stack_1[top_1];
		first = false;
	}
	std::cout << "]\n";
	std::cout << "   front -------^\n";
}

bool
MyQueue::stack_1_empty()
{
	return top_1 < 0;
}


bool
MyQueue::stack_2_empty()
{
	return top_2 < 0;
}
