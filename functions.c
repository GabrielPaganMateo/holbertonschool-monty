#include "monty.h"
char **tokens = NULL;
/**
 * push - push to an element to the stack
 */
void push(stack_t** stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	newnode->n = atoi(tokens[1]);
	newnode->next = *stack;
	newnode->prev = NULL;
	*stack = newnode;

	if (line_number)
	{

	}
}
/**
 * pall - print all
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	while (head != NULL)
	{
		printf("%i\n", head->n);
		head = head->next;
	}

	if (line_number)
	{

	}
}
