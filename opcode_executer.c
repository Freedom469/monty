#include "monty.h"

/**
 * execute - executes a Monty bytecode instruction
 * @instruction: instruction to execute
 * @line_number: current line number
 * @stack: pointer to the stack
 */
void execute(char *instruction, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	char *argument;

	opcode = strtok(instruction, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	argument = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		if (argument == NULL || !is_valid_integer(argument))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fflush(stderr);
			exit(EXIT_FAILURE);
		}
		push(stack, line_number, argument);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
