#include "stack.h"
#include "queue.h"

int
main()
{
	Stack_Min stack(15);

	if (stack.empty())
		std::cout << "\n\tStack is INDEED empty!\n";
	else
		std::cout << "\n\tStack is NOT empty!\n";

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	std::cout << "\n\n\tStack size: " << stack.size();
	stack.push(3);
	stack.push(7);
	stack.push(2);
	stack.push(9);
	stack.push(1);
	stack.push(3);
	stack.push(4);
	std::cout << "\n\tStack size: " << stack.size() << "\n";

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	int top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();

	stack.pop();

	std::cout << "\n\n\t================================";
	std::cout << "\n\tVisual representation of Stack: \n";
	stack.print_stack();
	std::cout << "\n\t================================";

	top = stack.peek();
	std::cout << "\n\tCurrently on the top of the stack: " << top;
	std::cout << "\n\tCurrent min: " << stack.min();
	std::cout << "\n\n";

	return 0;
}
