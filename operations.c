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
	stack_t *head = stack;

	while (head != NULL)
	{
		printf("%i\n", head->n);
		head = head->next;
	}
}
