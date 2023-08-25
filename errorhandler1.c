#include "monty.h"

int printer_poperrors(unsigned int line_number);
int printer_pinterror(unsigned int line_number);
int printer_matherrors(unsigned int line_number, char *op);
int printer_diverrors(unsigned int line_number);

/**
 * printer_poperrors - func to print pop error messages on empty stacks.
 * @line_number: location of number line error
 *
 * Return: return (EXIT_FAILURE) always.
 */
int printer_poperrors(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * printer_pinterror - func to print error messages for empty stacks.
 * @line_number: location of number line error
 *
 * Return: return (EXIT_FAILURE) always.
 */
int printer_pinterror(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * printer_matherrors - func to print monty math error messages
 *                     for stacks/queues lesser than 2 nodes.
 * @line_number: location of number line error
 * @op: error location of the operation
 *
 * Return: return (EXIT_FAILURE) always.
 */
int printer_matherrors(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * printer_diverrors - func to print div err messages by 0 division
 * @line_number: location of number line error
 *
 * Return: return (EXIT_FAILURE) always.
 */
int printer_diverrors(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

