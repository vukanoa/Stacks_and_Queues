#ifndef _QUEUE_H_
#define _QUEUE_H_

static const int CAPACITY = 10;

class Queue{
public:
	Queue(int capacity = CAPACITY);
	~Queue();

	void enqueue (int data);
	int  dequeue ();
	int  front   ();
	int  back    ();
	int  size    ();
	bool is_empty();
	bool is_full ();

private:
	int* queue;
	int capacity;
	int frontal;
	int rear;
	int filled;
};



/* Queue Problems */


// Queue via Stacks

class MyQueue{
public:
	MyQueue(int capacity = CAPACITY);
	~MyQueue();

	void enqueue (int data);
	void dequeue ();
	int  front   ();
	int  back    ();
	int  size    ();
	bool empty   ();
	bool full    ();

	void print_queue();

private:
	int* stack_1;
	int* stack_2;

	int capacity;
	int filled;
	int top_1;
	int top_2;

	bool stack_1_empty();
	bool stack_2_empty();
};


#endif // _QUEUE_H_
