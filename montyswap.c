#include "monty.h"

/**
 * imonty_swap - switches the top 2 value elements of a stack list
 * @stack: the pointer to the top node of the stack_t linked list.
 * @line_number: current working line number of the Monty bytecodes file.
 */
void imonty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpe;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_optokens(printer_matherrors(line_number, "swap"));
		return;
	}

	tmpe = (*stack)->next->next;
	(*stack)->next->next = tmpe->next;
	(*stack)->next->prev = tmpe;
	if (tmpe->next)
		tmpe->next->prev = (*stack)->next;
	tmpe->next = (*stack)->next;
	tmpe->prev = *stack;
	(*stack)->next = tmpe;
}
