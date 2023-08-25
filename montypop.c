#include "monty.h"

/**
 * imonty_pop - deletes top value element of stack_t linked list.
 * @stack: the npointer to the top mode node of a stack_t linked list.
 * @line_number: current working line number of the Monty bytecodes file
 */
void imonty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		error_optokens(printer_poperrors(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
