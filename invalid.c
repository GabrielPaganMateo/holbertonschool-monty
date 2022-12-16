#include "monty.h"
/**
 * invalid - throws an error if function is not found
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: opened file
 */
void invalid(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, tokens[0]);
	free(line);
	free_grid(tokens);
	free_stack(*stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

