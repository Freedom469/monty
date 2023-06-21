#include "monty.h"
/**
 * main - entry point to the programme
 * @argc: number of arguments
 * @argv: argmunents passed to the programme
 * Return: zero on success
 */
int main(int argc, char *argv[])
{	char *file_name;
	FILE *file;
	unsigned int line_number = 0;
	char line[256];
	int value;
	char command[256];
	stack_t *stack = NULL;
	char value_str[20];

	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{	file_name = argv[1];
		file = fopen(file_name, "r");
		if (file == NULL)
		{	fprintf(stderr, "Error: Can't open file %s\n", file_name);
			exit(EXIT_FAILURE);
		}
		while (fgets(line, sizeof(line), file) != NULL)
		{	line_number++;
			if (sscanf(line, "%s %d", command, &value) >= 1)
			{
				if (strcmp(command, "push") == 0)
				{	sprintf(value_str, "%d", value);
					push(&stack, line_number, value_str);
				}
				else if (strcmp(command, "pall") == 0)
				{	pall(&stack);
				}
				else if (strcmp(command, "pint") == 0)
				{
					pint(&stack);
				}
				else
				{	fprintf(stderr, "Error: L%u: unknown instruction %s\n",
						line_number, command);
				exit(EXIT_FAILURE);
				}
			}
		}
		fclose(file);
	}
	return (0);
}
