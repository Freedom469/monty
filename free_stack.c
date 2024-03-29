#include "monty.h"

/**
 * free_stack - frees the memory allocated for the stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
