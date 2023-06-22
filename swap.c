#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;
	int temp_value;

	top_node = *stack;

	if (top_node == NULL || top_node->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_value = top_node->n;
	top_node->n = top_node->next->n;
	top_node->next->n = temp_value;
}
