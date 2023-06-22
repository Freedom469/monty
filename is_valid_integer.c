#include "monty.h"

/**
 * is_valid_integer - checks if a string represents a valid integer
 * @str: string to check
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_valid_integer(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
