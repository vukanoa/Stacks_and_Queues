#include "stack.h"
#include "queue.h"

int
main()
{
	MyQueue my_queue(4);

	if (my_queue.empty())
		std::cout << "\n\tQueue is INDEED Empty!\n\n";
	else
		std::cout << "\n\tQueue is NOT Empty!\n\n";
	
	std::cout << "\n\tCurrent size of Queue: " << my_queue.size();
	
	my_queue.enqueue(1);
	my_queue.enqueue(2);
	my_queue.enqueue(3);
	my_queue.enqueue(4);

	std::cout << "\n\tCurrent size of Queue: " << my_queue.size();
	std::cout << "\n\n";

	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size();
	std::cout << "\n\tFront: " << my_queue.front();
	std::cout << "\n\tBack: " << my_queue.back()  << "\n\n";

	my_queue.dequeue();
	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size() << "\n";

	my_queue.dequeue();
	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size() << "\n";

	my_queue.dequeue();
	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size() << "\n";
	
	my_queue.dequeue();
	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size() << "\n";

	my_queue.enqueue(1);
	my_queue.enqueue(2);

	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size();
	std::cout << "\n\tFront: " << my_queue.front();
	std::cout << "\n\tBack: " << my_queue.back()  << "\n\n";
	
	my_queue.enqueue(4);
	my_queue.enqueue(5);

	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size();
	std::cout << "\n\tFront: " << my_queue.front();
	std::cout << "\n\tBack: " << my_queue.back()  << "\n\n";

	my_queue.enqueue(6);

	my_queue.print_queue();
	std::cout << "\tSize: " << my_queue.size();
	std::cout << "\n\tFront: " << my_queue.front();
	std::cout << "\n\tBack: " << my_queue.back()  << "\n\n";
	
	return 0;
}
