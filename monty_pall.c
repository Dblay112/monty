#include "monty.h"

/**
 * imonty_pall - func to print the values in a stack_t linked list.
 * @stack: pointer the top mode node of a stack_t linked list.
 * @line_number: current working line number of Monty bytecode
 */
void imonty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpe = (*stack)->next;

	while (tmpe)
	{
		printf("%d\n", tmpe->n);
		tmpe = tmpe->next;
	}
	(void)line_number;
}
