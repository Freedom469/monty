#include "monty.h"

void nop(stack_t **stack)
{
	(void)stack;
	/* Do nothing */
}

/**
 * main - entry point to the program
 * @argc: number of arguments
 * @argv: arguments passed to the program
 * Return: zero on success
 */
int main(int argc, char *argv[])
{
	char *file_name;
	FILE *file;
	unsigned int line_number = 0;
	char line[256];
	stack_t *stack = NULL;
	char *opcode;
	char *argument;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];
	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		argument = strtok(NULL, " \t\n");

		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, line_number, argument);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack);
		}
		else if(strcmp(opcode, "nop") == 0)
		{
			nop(&stack);
		}
		else
		{
			fprintf(stderr, "Error: L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	return 0;
}

