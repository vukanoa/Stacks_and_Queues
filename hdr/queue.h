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



// Definition for singly-linked list.
struct Node {
    bool dog;
	double arrival;
    Node *next;

    Node() : dog(true), arrival(0), next(nullptr) {}
    Node(bool dog) :dog(dog), arrival(0), next(nullptr) {}
    Node(bool dog, Node *next) : dog(true), arrival(0), next(next) {}
};

// Animal Shelter
class Queue_animal_shelter{
public:
	Queue_animal_shelter(int capacity = CAPACITY);
	~Queue_animal_shelter();

	void  enqueue    (Node* node);
	Node* dequeue_any();
	Node* dequeue_dog();
	Node* dequeue_cat();

	void  print_queue();

	static double arrived;

private:
	Node* queue;

	int capacity;
	int filled;
	Node *front_any;
	Node *front_dog;
	Node *front_cat;
	Node *rear;

};


#endif // _QUEUE_H_
