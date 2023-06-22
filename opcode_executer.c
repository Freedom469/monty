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
		push(stack, line_number, argument);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack,line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
