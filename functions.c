#include "monty.h"
#include "numberARG.h"
int num_arg = 0;
/**
 * push - push to an element to the stack
 */
void push(stack_t** stack)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	newnode->n = num_arg;
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
