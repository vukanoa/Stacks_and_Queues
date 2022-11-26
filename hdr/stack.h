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

#endif // _STACKS_H_
