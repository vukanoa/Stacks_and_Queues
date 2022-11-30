#include "stack.h"

Stack::Stack()
{
	filled = 0;
	capacity = 10;

	stack = new int[capacity];
}


Stack::Stack(int capacity)
	: capacity(capacity), filled(0), top(-1)
{
	stack = new int[capacity];
}


void
Stack::push(int data)
{
	if (top == capacity)
	{
		std::cout << "\n\tStack is Full! Unable to push a new element!\n";
		return;
	}

	stack[++top] = data;
	filled++;
}


void
Stack::pop()
{
	if (top < 0 || filled == 0)
	{
		std::cout << "\n\tStack is already empty! Unable to pop!\n";
		return;
	}

	top--;
	filled--;

	std::cout << "\n\tPop!\n";
}


bool
Stack::empty()
{
	return filled == 0;
}


int
Stack::size()
{
	return filled;
}


int
Stack::peek()
{
	if (top < 0 || filled == 0)
	{
		std::cout << "\n\tStack is Empty! There is no \'top\' element!\n";
		return -1;
	}

	return stack[top];
}

/* ------------------------------------------------------------------------- */


/*
	Three in One:
		Describe how you could use a single array to implement three stacks.
	

	1st Solution (Fixed Divisions):
		Let's say I have an array of length 10.

		I need to have "borders" at the end of 1st 1/3 portion and at the
		end of a 2nd 1/3.

		1 2 3 | 4 5 6 | 7 8 9

		0 1 2 3 | 4 5 6 | 7 8 9

		First  stack starts at position:  0.
		Second stack starts at position: length/3 + 1;
		Third  stack starts at position: 2 * length/3 + 1;

		First  stack ends at position: lenght/3
		Second stack ends at position: 2 * length/3 + 1;
		Third  stack ends at position: lenght - 1
	
	2nd Solution (Flexible Divisions):
		Allow the stack blocks to be flexible in size. When one stack exceeds
		its initial capacity, grow the allowable capacity and shift elements
		as necessary.

		We will also design our array to be circular, such that the final stack
		may start at the end of the array and wrap around to the beginning.
*/

FixedMultiStack::FixedMultiStack(int stack_capacity) : stack_capacity(stack_capacity)
{
	values     = new int[stack_capacity * number_of_stacks];
	capacities = new int[number_of_stacks];
}


void
FixedMultiStack::push(int stack_number, int value)
{
	if (full(stack_number))
	{
		std::cout << "\n\tStack number: " << stack_number << " is already full! Unable to push!\n\n";
		return;
	}

	capacities[stack_number]++;
	values[top_index(stack_number)] = value;
}


int
FixedMultiStack::pop(int stack_number)
{
	if (empty(stack_number))
	{
		std::cout << "\n\tStack number: " << stack_number << " is empty! Unable to pop!\n\n";
		return;
	}
}


int
FixedMultiStack::peek(int stack_number)
{
	if (empty(stack_number))
	{
		std::cout << "\n\tStack number: " << stack_number << " is empty! Unable to pop!\n\n";
		return;
	}

	return values[top_index(stack_number)];
}


bool
FixedMultiStack::empty(int stack_number)
{
	return capacities[stack_number] == 0;
}


bool
FixedMultiStack::full(int stack_number)
{
	return capacities[stack_number] == stack_capacity;
}


int
FixedMultiStack::top_index(int stack_number)
{
	int offset = stack_number * stack_capacity;
	int capacity = capacities[stack_number];

	return offset + capacity - 1;
}


/* ------------------------------------------------------------------------- */

class MultiStack{
private:
	class StackInfo{
	public:
		int start;
		int size;
		int capacity;

		StackInfo(int start, int capacity)
		{
			this.start = start;
			this.capacity = capacity;
		}

		bool is_within_stack_capacity(int index)
		{
			if (index < 0 || index >= values.length)
				return false;

			/* If Index wraps around, adjust it */
			int contiguousIndex = index < start ? index + values.length : index;
			int end = start + capacity;

			return start <= contiguousIndex && contiguousIndex < end;
		}

		int last_capacity_index()
		{
			return adjust_index(start + capacity - 1);
		}

		int last_element_index()
		{
			return adjust_index(start + size - 1);
		}

		bool is_full()
		{
			return size == capacity;
		}

		bool is_empty()
		{
			return size == 0;
		}

	};

	MultiStack(int number_of_stacks, int default_size)
	{
		/* Create metadata for all the stacks */
		info = new StackInfo[number_of_stacks];

		for (int i = 0; i < number_of_stacks; i++)
			info[i] = new StackInfo(default_size * i, default_size);

		values = new int[number_of_stacsk * default_size];
	}

	/* Push value onto stack num, shifting/expanding stacks as necessary */
	void push(int stack_number, int value)
	{
		if (all_stacks_are_full())
		{
			std::cout << "\n\tException: All stacks are full!\n";
			exit(-1);
		}

		/* If this stack is full, expand it */
		StackInfo stack = info[stack_number];
		if (stack.is_full())
			expand(stack_number);

		/*
			Find the Index of the top element in the array + 1, and increment
			the stack pointer
		*/
		stack.size++;
		values[stack.last_element_index()] = value;
	}

	/* Remove value from stack */
	int pop(int stack_number)
	{
		StackInfo stack = info[stack_number];
		if (stack.is_empty())
		{
			std::cout << "\n\tException: Stack is Empty!\n";
			exit(-1);
		}

		/* Remove last element */
		int value = values[stack.last_element_index()];
		values[stack.last_element_index()] = 0; // Clear item
		stack.size--;

		return value;
	}

	/* Get top element of stack */
	int peek(int stack_number)
	{
		StackInfo stack = info[stack_number];

		return values[stack.last_element_index()];
	}

	/* Returns true if all the stacks are full */
	bool all_stacks_are_full()
	{
		return number_of_elements() == values.length;
	}

private:
	StackInfo* info[];
	int values[];

	/*
		Shift items in stack over by one element. If we have available capacity
		then we'll end up shrinking the stack by one element. If we don't have
		available capacity, then we'll need to shift the next stack over too 
	*/
	void shift(int stack_number)
	{
		std::cout << "\n\tShifting " << stack_number << "\n";
		StackInfo stack = info[stack_number];

		/*
			If this stack is at its full capacity, then you need to move the
			next stack over by one element. This stack can now claim the freed
			index.
		*/
		if (stack.size >= stack.capacity)
		{
			int next_stack = (stack_number + 1) % info.length;
			shift(next_stack);
			stack.capacity++; // claim index that the next stack lost
		}

		/* Shift all elememnts in stack over by one */
		int index = stack.last_capacity_index();

		while (stack.is_within_stack_capacity(index))
		{
			values[index] = values[previous_index(index)];
			index = previous_index(index);
		}

		/* Adjust the stack data */
		values[stack.start] = 0; // Clear item
		stack.start = next_index(stack.start); // Move start
		stack.capacity--;
	}

	/* Expand stack by shifting over other stacks */
	void expand(int stack_number)
	{
		shift((stack_number + 1) % info.length);
		info[stack_number].capacity++;
	}

	/* Adjust index to be within the range of 0 -> length - 1 */
	int adjust_index(int index)
	{
		int max = values.length;

		return ((index % max) + max) % max;
	}

	/* Get index before this index, adjusted for wrap around */
	int next_index(int index)
	{
		return adjust_index(index + 1);
	}

	/* Get index before this index, adjusted for wrap around */
	int previous_index(int index)
	{
		return adjust_index(index - 1);
	}
};
