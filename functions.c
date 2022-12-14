#include "monty.h"
char **tokens = NULL;
/**
 * push - push to an element to the stack
 */
void push(stack_t** stack, unsigned int line_number, char *line)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (tokens[1] == NULL || isdigit(*tokens[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(line);
		free_grid(tokens);
		free(newnode);
		free_stack(*stack);
		/*close file*/
		exit(EXIT_FAILURE);
	}

	newnode->n = atoi(tokens[1]);
	newnode->next = *stack;
	newnode->prev = NULL;
	*stack = newnode;
}
/**
 * pall - print all
 */
void pall(stack_t **stack, unsigned int line_number, char *line)
{
	stack_t *head = *stack;
	(void)line;

	while (head != NULL)
	{
		printf("%i\n", head->n);
		head = head->next;
	}

	if (line_number)
	{

	}
}
