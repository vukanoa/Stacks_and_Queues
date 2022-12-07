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

/* ------------------------------------------------------------------------- */

double Queue_animal_shelter::arrived = 1;

// Constructor
Queue_animal_shelter::Queue_animal_shelter(int capacity)
	: capacity(capacity), filled(0),
	  front_any(nullptr), front_dog(nullptr), front_cat(nullptr), rear(nullptr)
{
	queue = nullptr;
	// opening_time = std::chrono::steady_clock::now();
}

// Destructor
Queue_animal_shelter::~Queue_animal_shelter()
{}

void
Queue_animal_shelter::enqueue(Node* node)
{
	node->arrival = Queue_animal_shelter::arrived++;

	if (queue == nullptr)
	{
		queue = rear = node;
		if (node->dog)
			front_dog = node;
		else
			front_cat = node;

		front_any = node;
	}
	else
	{
		rear->next = node;
		rear = rear->next;

		if (node->dog && front_dog == nullptr)
			front_dog = node;
		else if (!node->dog && front_cat == nullptr)
			front_cat = node;
	}

}


Node*
Queue_animal_shelter::dequeue_any()
{
	if (queue != nullptr)
	{
		Node* ret = queue;
		front_any = queue->next;
		queue = queue->next;

		Node* tmp = queue;
		if (ret->dog)
		{
			while (!tmp->dog && tmp != nullptr)
				tmp = tmp->next;

			front_dog = tmp;
		}
		else
		{
			while (tmp->dog && tmp != nullptr)
				tmp = tmp->next;

			front_cat = tmp;
		}

		return ret;
	}

	return nullptr;
}


Node*
Queue_animal_shelter::dequeue_dog()
{
	if (front_dog == nullptr)
	{
		std::cout << "\n\t\tThere is no Dog available in the Animal Shelter!\n\n";
		return nullptr;
	}
	else
	{
		Node* ret = front_dog;
		front_dog = front_dog->next;

		while (front_dog != nullptr && !front_dog->dog)
			front_dog = front_dog->next;

		if (queue == ret)
			queue = queue->next;
		else
		{
			Node* tmp = queue;
			while (tmp->next != ret)
				tmp = tmp->next;

			tmp->next = tmp->next->next;
		}

		return ret;
	}
}


Node*
Queue_animal_shelter::dequeue_cat()
{
	if (front_cat == nullptr)
	{
		std::cout << "\n\t\tThere is no Cat available in the Animal Shelter!\n\n";
		return nullptr;
	}
	else
	{
		Node* ret = front_cat;
		front_cat = front_cat->next;

		while (front_cat != nullptr && front_cat->dog)
			front_cat = front_cat->next;

		if (queue == ret)
			queue = queue->next;
		else
		{
			Node* tmp = queue;
			while (tmp->next != ret)
				tmp = tmp->next;

			tmp->next = tmp->next->next;
		}

		return ret;
	}
}


void
Queue_animal_shelter::print_queue()
{
	Node* tmp = queue;

	while (tmp)
	{
		auto arrived = tmp->arrival;
		if (tmp->dog && queue == tmp)
			std::cout << "\n 1st -> " << "Animal: DOG\n\tArrival: " << arrived << "\n";
		else if (tmp->dog)
			std::cout << "\n\t" << "Animal: DOG\n\tArrival: " << arrived << "\n";
		else if (!tmp->dog && queue == tmp)
			std::cout << "\n 1st -> " << "Animal: CAT\n\tArrival: " << arrived << "\n";
		else
			std::cout << "\n\t" << "Animal: CAT\n\tArrival: " << arrived << "\n";

		tmp = tmp->next;
	}

	std::cout << "\n\n";
}
