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

/* ------------------------------------------------------------------------- */


/*
	Three in One:
		Describe how you could use a single array to implement three stacks.
	

	1st Solution (Fixed Divisions):
		Let's say I have an array of length 10.

		I need to have "borders" at the end of 1st 1/3 portion and at the
		end of a 2nd 1/3.

		1 2 3 | 4 5 6 | 7 8 9

		0 1 2 3 | 4 5 6 | 7 8 9

		First  stack starts at position:  0.
		Second stack starts at position: length/3 + 1;
		Third  stack starts at position: 2 * length/3 + 1;

		First  stack ends at position: lenght/3
		Second stack ends at position: 2 * length/3 + 1;
		Third  stack ends at position: lenght - 1
	
	2nd Solution (Flexible Divisions):
		Allow the stack blocks to be flexible in size. When one stack exceeds
		its initial capacity, grow the allowable capacity and shift elements
		as necessary.

		We will also design our array to be circular, such that the final stack
		may start at the end of the array and wrap around to the beginning.
*/

FixedMultiStack::FixedMultiStack(int stack_capacity) : stack_capacity(stack_capacity)
{
	values     = new int[stack_capacity * number_of_stacks];
	capacities = new int[number_of_stacks];
}


void
FixedMultiStack::push(int stack_number, int value)
{
	if (full(stack_number))
	{
		std::cout << "\n\tStack number: " << stack_number << " is already full! Unable to push!\n\n";
		return;
	}

	capacities[stack_number]++;
	values[top_index(stack_number)] = value;
}


int
FixedMultiStack::pop(int stack_number)
{
	if (empty(stack_number))
	{
		std::cout << "\n\tStack number: " << stack_number << " is empty! Unable to pop!\n\n";
		return;
	}
}


int
FixedMultiStack::peek(int stack_number)
{
	if (empty(stack_number))
	{
		std::cout << "\n\tStack number: " << stack_number << " is empty! Unable to pop!\n\n";
		return;
	}

	return values[top_index(stack_number)];
}


bool
FixedMultiStack::empty(int stack_number)
{
	return capacities[stack_number] == 0;
}


bool
FixedMultiStack::full(int stack_number)
{
	return capacities[stack_number] == stack_capacity;
}


int
FixedMultiStack::top_index(int stack_number)
{
	int offset = stack_number * stack_capacity;
	int capacity = capacities[stack_number];

	return offset + capacity - 1;
}
