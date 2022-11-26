#include "stack.h"

int
main()
{
	Stack stack(15);

	if (stack.empty())
		std::cout << "\n\tStack is INDEED empty!\n";
	else
		std::cout << "\n\tStack is NOT empty!\n";

	std::cout << "\n\tStack size: " << stack.size() << "\n";
	stack.push(7);
	stack.push(9);
	stack.push(2);
	stack.push(1);
	stack.push(3);
	stack.push(4);
	std::cout << "\n\tStack size: " << stack.size() << "\n";

	int top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top << "\n";

	stack.pop();

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top << "\n";
	std::cout << "\n";

	return 0;
}
