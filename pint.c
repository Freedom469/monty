#include "monty.h"
/**
 * pint -  prints the value at the top of the stack,
 *  followed by a new line.
 *  @stack: pointer to pointer of the stack
 *  @line_number: opcode number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	if (current)
	{
		printf("%d\n", current->n);
	}

	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fflush(stderr);
		exit(EXIT_FAILURE);
	}
}
