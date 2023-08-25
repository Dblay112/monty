#include "monty.h"

int monty_errorprinter(void);
int monty_mallocerror(void);
int fileopen_error(char *filename);
int unknown_errorprinter(char *opcode, unsigned int line_number);
int pusherror_printer(unsigned int line_number);

/**
 * monty_errorprinter - func to print usual errors messages
 *
 * Return: always return - (EXIT_FAILURE)
 */
int monty_errorprinter(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * monty_mallocerror - func to print malloc err messages
 *
 * Return: always return - (EXIT_FAILURE)
 */
int monty_mallocerror(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * fileopen_error - func to print file opening error messages
 * with file name
 * @filename: file to be opened name
 *
 * Return: always return - (EXIT_FAILURE)
 */
int fileopen_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_errorprinter - func to print unknown instruc. err messages
 * @opcode: location of where the error occured
 * @line_number: location of file error in monty bytecodes file from line  * number.
 *
 * Return: always return - (EXIT_FAILURE)
 */
int unknown_errorprinter(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * pusherror_printer - func to print invalide monty push arg err messages
 * @line_number: location of file error in monty bytecodes file from line  * number.
 * Return: always return - (EXIT_FAILURE)
 */
int pusherror_printer(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
