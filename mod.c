#include "monty.h"

/**
 * mod -  computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n %= temp->n;

	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
