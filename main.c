#include "monty.h"
/**
 * main - entry point to the program
 * @argc: number of arguments
 * @argv: arguments passed to the program
 * Return: zero on success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	run_monty_file(argv[1]);

	return (0);
}
