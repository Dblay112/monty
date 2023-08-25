#include "monty.h"
#include <string.h>

void freedmonty(stack_t **stack);
int montyinit(stack_t **stack);
int montymode(stack_t *stack);

/**
 * freedmonty - func to free a stack_t stack.
 * @stack: A pointer to the top of slack or
 *         bsottom (queue) of a stack_t.
 */
void freedmonty(stack_t **stack)
{
	stack_t *tmpe = *stack;

	while (*stack)
	{
		tmpe = (*stack)->next;
		free(*stack);
		*stack = tmpe;
	}
}

/**
 * montyinit - starts a stack_t stack with first
 *              stack and ending queue nodes
 * @stack: unitialized stack_t stack pointera
 *
 * Return: on error - EXIT_FAILURE.
 *         else - EXIT_SUCCESS.
 */
int montyinit(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (monty_mallocerror());

	s->n = IMONTY_STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * montymode - finds a stack_t linked list in stack or queue mode.
 * @stack: the pointer to top or bottom of the stack
 *         ofs a stack_t linked list.
 *
 * Return: success in stack - IMONTYSTACK (0).
 *         stack_t in queue mode - IMONTY_QUEUE (1).
 *         else - 2.
 */
int montymode(stack_t *stack)
{
	if (stack->n == IMONTY_STACK)
		return (IMONTY_STACK);
	else if (stack->n == IMONTY_QUEUE)
		return (IMONTY_QUEUE);
	return (2);
}
