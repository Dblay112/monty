#include "monty.h"

/**
 * imonty_pint - func to print top value of a stack_t linked list.
 * @stack: pointer to the top node of stack_t linked list.
 * @line_number: current working line no of a Monty bytecodes file.
 */
void imonty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		error_optokens(printer_pinterror(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
