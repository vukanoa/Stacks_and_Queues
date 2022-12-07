#include "stack.h"
#include "queue.h"


int
main()
{
	Queue_animal_shelter animal_shelter;
	Node dog_1;
	Node dog_2;
	Node cat_1(false); // false - meaning not a dog => cat
	Node cat_2(false);
	Node dog_3;
	Node cat_3(false);
	Node cat_4(false);

	animal_shelter.enqueue(&dog_1);
	animal_shelter.enqueue(&dog_2);
	animal_shelter.enqueue(&cat_1);
	animal_shelter.enqueue(&cat_2);
	animal_shelter.enqueue(&dog_3);
	animal_shelter.enqueue(&cat_3);
	animal_shelter.enqueue(&cat_4);

	animal_shelter.print_queue();

	/* Take ANY animal */
	Node* took_animal_1 = animal_shelter.dequeue_any();
	if (took_animal_1->dog)
		std::cout << "\n\t\tANY: DOG(" << took_animal_1->arrival << ")\n\n";
	else
		std::cout << "\n\t\tANY: CAT(" << took_animal_1->arrival << ")\n\n";

	animal_shelter.print_queue();


	/* Take a DOG */
	Node* took_dog_1 = animal_shelter.dequeue_dog();
	if (took_dog_1)
		std::cout << "\n\t\tLast Dog: DOG(" << took_dog_1->arrival << ")\n\n";

	animal_shelter.print_queue();


	/* Take a CAT */
	Node* took_cat_1 = animal_shelter.dequeue_cat();
	if (took_cat_1)
		std::cout << "\n\t\tLast Cat: CAT(" << took_cat_1->arrival << ")\n\n";

	animal_shelter.print_queue();

	/* Take ANY animal */
	Node* took_animal_2 = animal_shelter.dequeue_any();
	if (took_animal_2->dog)
		std::cout << "\n\t\tANY: DOG(" << took_animal_2->arrival << ")\n\n";
	else
		std::cout << "\n\t\tANY: CAT(" << took_animal_2->arrival << ")\n\n";

	animal_shelter.print_queue();


	Node* took_dog_2 = animal_shelter.dequeue_dog();
	animal_shelter.print_queue();

	Node* took_dog_3 = animal_shelter.dequeue_dog();
	animal_shelter.print_queue();

	return 0;
}

