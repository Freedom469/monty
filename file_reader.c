#include "monty.h"

/**
 * run_monty_file - reads a Monty bytecode file and executes the instructions
 * @file_name: name of the Monty file to execute
 */
void run_monty_file(char *file_name)
{
	char *trimmed_line;
	unsigned int line_number = 0;
	char line[256];
	stack_t *stack = NULL;
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		trimmed_line = trim_whitespace(line);
		if (trimmed_line[0] == '\0' || trimmed_line[0] == '#')
			continue;
		execute(trimmed_line, line_number, &stack);
	}

	fclose(file);
	free_stack(&stack);
}

