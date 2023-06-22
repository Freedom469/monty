#include "monty.h"

/**
 * sub - sub the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n -= temp->n;

	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
