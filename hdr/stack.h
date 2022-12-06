#ifndef _STACKS_H_
#define _STACKS_H_

#include <iostream>
#include <vector>

class Stack{
public:
	Stack();
	Stack(int capacity);

	void push (int data);
	void pop  ();
	int  size ();
	bool empty();
	int  peek ();

	void print_stack();

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


// Stack Min

class Stack_Min{
public:
	Stack_Min();
	Stack_Min(int capacity);

	void push (int data);
	void pop  ();
	int  peek ();
	int  size ();
	bool empty();

	void push_min (int data);
	void pop_min  ();
	bool empty_min();
	int  min      ();

	void print_stack();

private:
	int capacity;

	int filled;
	int top;
	int* stack;

	int filled_min;
	int top_min;
	int* stack_min;
};


// Stack of Plates

class SetOfStacks{
public:
	SetOfStacks();
	SetOfStacks(int capacity);

	void push (int data);
	void pop  ();
	int  size ();
	bool empty();
	int  peek ();
	int  used_stacks ();
	void print_stacks();
	
	/* 
		We're told to implement this function.
		Everything else is just so we can implement this.
	*/
	void pop_at(int index);

private:
	int capacity;
	int filled;
	int top;
	int available_stack;
	std::vector<int*>stacks;
};



// Sort Stack
Stack* sort_stack(Stack* stack);
void   stack_sort(Stack* stack);

#endif // _STACKS_H_
