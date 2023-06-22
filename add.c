#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n += temp->n;

	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
