#ifndef _STACKS_H_
#define _STACKS_H_

#include <iostream>

class Stack{
public:
	Stack();
	Stack(int capacity);

	void push (int data);
	void pop  ();
	bool empty();
	int  size ();
	int  peek ();

private:
	int capacity;
	int filled;
	int top;
	int* stack;
};

/* Stack Problems */

// Three in one

class FixedMultiStack{
public:
	FixedMultiStack(int stack_capacity);
	void push (int stack_number, int value);
	int  pop  (int stack_number);
	int  peek (int stack_number);
	bool empty(int stack_number);
	bool full (int stack_number);
	int  top_index(int stack_number);

private:
	int number_of_stacks = 3;
	int stack_capacity;
	int *values;
	int *capacities;
};


#endif // _STACKS_H_
