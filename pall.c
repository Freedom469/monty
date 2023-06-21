#include "main.h"

/**
 * pall -  prints all the values on the stack,
 *  starting from the top of the stack.
 *  @stack: a pointer to a pointer to the stack
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

