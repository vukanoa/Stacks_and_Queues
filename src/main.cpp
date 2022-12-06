#include "stack.h"
#include "queue.h"

int
main()
{
	Stack stack;

	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(2);
	stack.push(8);
	stack.push(1);

	stack.print_stack();

	/* First solution */
	sort_stack(&stack);

	stack.print_stack();

	return 0;
}
