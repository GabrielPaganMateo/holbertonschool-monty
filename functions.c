#include "monty.h"
char **tokens = NULL;
/**
 * push - push to an element to the stack
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: file opened
 */
void push(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (tokens[1] == NULL || check_arg(tokens[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(line);
		free_grid(tokens);
		free(newnode);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}


	newnode->n = atoi(tokens[1]);
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
/**
 * pall - print all
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: file opened
 */
void pall(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *head = *stack;

	(void)line;
	(void)file;
	(void)line_number;
	while (head != NULL)
	{
		printf("%i\n", head->n);
		head = head->next;
	}
}
/**
 * pint - print value at top
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: file opened
 */
void pint(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		printf("%i\n", head->n);
	}
	else if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(line);
		free_grid(tokens);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - removes top element of the stack
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: file opened
 */
void pop(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		*stack = (*stack)->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		free(head);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(line);
		free_grid(tokens);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
