#include "stack.h"
#include "queue.h"

int
main()
{
	Queue queue(5);

	if (queue.is_empty())
		std::cout << "\n\tQueue is INDEED Empty!\n";
	else
		std::cout << "\n\tQueue is NOT Empty!\n";

	std::cout << "\n\t*** Pushing Elements ***\n";
	queue.enqueue(5);
	queue.enqueue(7);
	queue.enqueue(1);

	std::cout << "\n\tFront: " << queue.front();
	std::cout << "\n\tRear: " << queue.back() << "\n";

	queue.dequeue();

	std::cout << "\n\tFront: " << queue.front();
	std::cout << "\n\tRear: " << queue.back() << "\n";

	std::cout << "\n";

	return 0;
}
