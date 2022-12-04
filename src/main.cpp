#include "stack.h"
#include "queue.h"

int
main()
{
	SetOfStacks stacks(5);

	if (stacks.empty())
		std::cout << "\n\tStacks are INDEED empty!\n";
	else
		std::cout << "\n\tStacks are NOT empty!\n";

	std::cout << "\n\tNumber of used stacks: " << stacks.used_stacks();
	std::cout << "\n\tTotal Stack size: " << stacks.size();
	/*
		1 - 2
		2 - 2
		3 - 1
		4 - 2
		5 - 1
		6 - 1
		7 - 2
		8 - 1
		9 - 2
	*/
	stacks.push(3);
	stacks.push(7);
	stacks.push(2);
	stacks.push(9);
	stacks.push(1);
	stacks.push(8);
	stacks.push(4);
	stacks.push(5);
	stacks.push(2);
	stacks.push(1);
	stacks.push(4);
	stacks.push(7);
	stacks.push(9);
	stacks.push(6);
	std::cout << "\n\n\tNumber of used stacks: " << stacks.used_stacks();
	std::cout << "\n\tTotal Stack size: " << stacks.size() << "\n";

	std::cout << "\n\t----------------------------------------------";
	stacks.print_stacks();
	std::cout << "\n";
	for (int i = 0; i < stacks.used_stacks(); i++)
	{
		std::cout << "\tStk_" << i + 1;
	}
	std::cout << "\n\t----------------------------------------------\n\n";




	/* The whole problem was about this function */
	stacks.pop_at(8);

	std::cout << "\n\t----------------------------------------------";
	stacks.print_stacks();
	std::cout << "\n";
	for (int i = 0; i < stacks.used_stacks(); i++)
	{
		std::cout << "\tStk_" << i + 1;
	}
	std::cout << "\n\t----------------------------------------------";

	int top = stacks.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tNumber of used stacks: " << stacks.used_stacks();




	stacks.pop();

	std::cout << "\n\t----------------------------------------------";
	stacks.print_stacks();
	std::cout << "\n";
	for (int i = 0; i < stacks.used_stacks(); i++)
	{
		std::cout << "\tStk_" << i + 1;
	}
	std::cout << "\n\t----------------------------------------------";

	top = stacks.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tNumber of used stacks: " << stacks.used_stacks();




	stacks.pop();

	std::cout << "\n\t----------------------------------------------";
	stacks.print_stacks();
	std::cout << "\n";
	for (int i = 0; i < stacks.used_stacks(); i++)
	{
		std::cout << "\tStk_" << i + 1;
	}
	std::cout << "\n\t----------------------------------------------";

	top = stacks.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tNumber of used stacks: " << stacks.used_stacks();
	std::cout << "\n\n";
	
	return 0;
}
