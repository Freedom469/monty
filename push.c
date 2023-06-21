#include "monty.h"

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - pushes a node struct to the stack
 * @stack: storage where the node will be pushed
 * @line_number: number of opcode in a monty file
 * @arg: A string representing the value to push onto the stack.
 */


void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int value = 0;

	if (arg == NULL || check_for_digit(arg))
	{
		fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	if (value == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Create a new node and add it to the top of the stack */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
