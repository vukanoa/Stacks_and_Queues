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

#endif // _QUEUE_H_
