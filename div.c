#include "monty.h"

/**
 * monty_div -  divides the second top element of the
 * stack by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n /= temp->n;

	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
