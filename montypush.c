#include "monty.h"

void imonty_push(stack_t **stack, unsigned int line_number);

/**
 * imonty_push - push a value to the top of the linked list
 * @stack: the pointer to the top mode node of the stack_t linked list.
 * @line_number: current working line number of the Monty bytecodes file.
 */
void imonty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpe, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		error_optokens(monty_mallocerror());
		return;
	}

	if (op_toks[1] == NULL)
	{
		error_optokens(pusherror_printer(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			error_optokens(pusherror_printer(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (montymode(*stack) == IMONTY_STACK)
	{
		tmpe = (*stack)->next;
		new->prev = *stack;
		new->next = tmpe;
		if (tmpe)
			tmpe->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmpe = *stack;
		while (tmpe->next)
			tmpe = tmpe->next;
		new->prev = tmpe;
		new->next = NULL;
		tmpe->next = new;
	}
}
