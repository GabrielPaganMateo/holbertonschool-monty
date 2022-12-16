#include "monty.h"
/**
 * swap - swap top two elements of the stack
 */
void swap(stack_t** stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *head = *stack;
	stack_t *body = (*stack)->next;
	int head_value;
	int body_value;

	if (body != NULL)
	{
		head_value = head->n;
		body_value = body->n;
		head->n = body_value;
		body->n = head_value;
	}
	else if (body == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(line);
		free_grid(tokens);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}



