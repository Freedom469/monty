#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: the stack srorange to delete the node from
 * @line_number: number of opcodes in a monty file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		if (temp->next != NULL)
		{
			(*stack) = temp->next;
			(*stack)->prev = NULL;

		}

		else
		{
			*stack = NULL;
		}
	}

	free(temp);
}
