#include "monty.h"

void imonty_nop(stack_t **stack, unsigned int line_number);

/**
 * imonty_nop - does not do anything for the Monty Code.
 * @stack: pointer to the top mode nodse of a stack_t linked list.
 * @line_number: current working line number of Monty bytecodes file
 */
void imonty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
