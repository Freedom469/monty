#include "monty.h"

/**
 * mul - multiplies the second top element of
 * the stack with the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n *= temp->n;

	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
