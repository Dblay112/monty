#include "monty.h"
#include <string.h>


void free_montytokens(void);
unsigned int montytokenlen(void);
int monty_emptyline(char *line, char *delims);
void (*monty_getop(char *opcode))(stack_t**, unsigned int);
int exe_monty(FILE *script_fd);

/**
 * free_montytokens - func to frees the global op_toks array of strings.
 */
void free_montytokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * montytokenlen - function to get the length of current op_toks.
 *
 * Return: length of the optoks.
 */
unsigned int montytokenlen(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * monty_emptyline- function to check delimiting char from getline.
 * @line: line pointer
 * @delims: delimiting char string to use
 *
 * Return: success -1 failure 0
 */
int monty_emptyline(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * monty_getop - finds an opcode and matches
 * @opcode: opcode to use to match.
 *
 * Return: correspondin func pointer
 */
void (*monty_getop(char *opcode))(stack_t**, unsigned int)
{
	instruction_t _getop[] = {
		{"push", imonty_push},
		{"pall", imonty_pall},
		{"pint", imonty_pint},
		{"pop", imonty_pop},
		{"swap", imonty_swap},
		{"nop", imonty_nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; _getop[i].opcode; i++)
	{
		if (strcmp(opcode, _getop[i].opcode) == 0)
			return (_getop[i].f);
	}

	return (NULL);
}

/**
 * exe_monty - function to execute a Monty bytecodes script
 * @monty_fd: fd to open Monty bytecodes script
 *
 * Return: xEXIT_SUCCESS on success
 */
int exe_monty(FILE *monty_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*_getop)(stack_t**, unsigned int);

	if (montyinit(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, monty_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, IMONTY_DELIMS);
		if (op_toks == NULL)
		{
			if (monty_emptyline(line, IMONTY_DELIMS))
				continue;
			freedmonty(&stack);
			return (monty_mallocerror());
		}
		else if (op_toks[0][0] == '#')
		{
			free_montytokens();
			continue;
		}
		_getop = monty_getop(op_toks[0]);
		if (_getop == NULL)
		{
			freedmonty(&stack);
			exit_status = unknown_errorprinter(op_toks[0], line_number);
			free_montytokens();
			break;
		}
		prev_tok_len = montytokenlen();
		_getop(&stack, line_number);
		if (montytokenlen() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_montytokens();
			break;
		}
		free_montytokens();
	}
	freedmonty(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (monty_mallocerror());
	}

	free(line);
	return (exit_status);
}
