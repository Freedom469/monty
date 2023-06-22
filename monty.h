#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STDOUT_FILENO 1
#include <ctype.h>

extern char *file;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pall(stack_t **stack);
void push(stack_t **stack, unsigned int line_number, char *arg);
void pint(stack_t **stack , unsigned int line_number);
void free_stack(stack_t **stack);
int check_for_digit(char *arg);
void nop(stack_t **stack);
void run_monty_file(char *file_name);
void execute(char *instruction, unsigned int line_number, stack_t **stack);
int is_valid_integer(char *str);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

#endif
