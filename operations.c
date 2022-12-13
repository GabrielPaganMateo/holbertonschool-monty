#include "monty.h"
/**
 * push - push to an element to the stack
 */
void push(stack_t** stack, int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	newnode->n = n;
	newnode->next = *stack;
	newnode->prev = NULL;
	*stack = newnode;
}
/**
 * pall - print all
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%i\n", stack->n);
		stack = stack->next;
	}
}
