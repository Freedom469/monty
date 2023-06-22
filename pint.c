#include "monty.h"
/**
 * pint -  prints the value at the top of the stack,
 *  followed by a new line.
 *  @stack: pointer to pointer of the stack
 */

void pint(stack_t **stack)
{
	int line_number = 0;
	stack_t *current;

	current = *stack;

	if (current)
	{
		printf("%d\n", current->n);
		line_number++;
	}

	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
