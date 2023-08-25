#ifndef __MONTY_H__
#define __MONTY_H__
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **op_toks;

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

#define IMONTY_STACK 0
#define IMONTY_QUEUE 1
#define IMONTY_DELIMS " \n\t\a\b"

void freedmonty(stack_t **stack);
int montyinit(stack_t **stack);
int montymode(stack_t *stack);
void free_tokens(void);
unsigned int montytokenlen(void);
int exe_monty(FILE *script_fd);
void error_optokens(int err_code);


void imonty_push(stack_t **stack, unsigned int line_number);
void imonty_pall(stack_t **stack, unsigned int line_number);
void imonty_pint(stack_t **stack, unsigned int line_number);
void imonty_pop(stack_t **stack, unsigned int line_number);
void imonty_swap(stack_t **stack, unsigned int line_number);
void imonty_add(stack_t **stack, unsigned int line_number);
void imonty_nop(stack_t **stack, unsigned int line_number);


char **strtow(char *str, char *delims);
char *chari_intget(int n);


int monty_errorprinter(void);
int monty_mallocerror(void);
int fileopen_error(char *filename);
int unknown_errorprinter(char *opcode, unsigned int line_number);
int pusherror_printer(unsigned int line_number);
int printer_poperrors(unsigned int line_number);
int printer_pinterror(unsigned int line_number);
int printer_matherrors(unsigned int line_number, char *op);
int printer_diverrors(unsigned int line_number);
int printer_pcharerrors(unsigned int line_number, char *message);

#endif
