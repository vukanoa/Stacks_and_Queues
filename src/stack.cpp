#include "stack.h"

Stack::Stack()
{
	filled = 0;
	capacity = 10;

	stack = new int[capacity];
}


Stack::Stack(int capacity)
	: capacity(capacity), filled(0), top(-1)
{
	stack = new int[capacity];
}

void
Stack::push(int data)
{
	if (top == capacity)
	{
		std::cout << "\n\tStack is Full! Unable to push a new element!\n";
		return;
	}

	stack[++top] = data;
	filled++;
}


void
Stack::pop()
{
	if (top < 0 || filled == 0)
	{
		std::cout << "\n\tStack is already empty! Unable to pop!\n";
		return;
	}

	top--;
	filled--;

	std::cout << "\n\tPop!\n";
}


bool
Stack::empty()
{
	return filled == 0;
}


int
Stack::size()
{
	return filled;
}


int
Stack::peek()
{
	if (top < 0 || filled == 0)
	{
		std::cout << "\n\tStack is Empty! There is no \'top\' element!\n";
		return -1;
	}

	return stack[top];
}
