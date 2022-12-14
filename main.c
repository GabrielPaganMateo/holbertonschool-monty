#include "monty.h"
/**
 * main - main function of monty program, accepts command for updating
 * stacks & queues
 */
int main(int argc, char *argv[])
{
	/*getline*/
	FILE *file;
	char *line = NULL;
	size_t buflen = 0;

	/*tokenization*/

	/*define stack & head*/
	stack_t *stack = NULL;

	/*line_number*/
	static unsigned int line_number = 0;

	if (argc != 2)
		exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");

	while (getline(&line, &buflen, file) != -1)
	{
		line_number++;
		tokens = tokenization(line, " \n");
		call_function(tokens)(&stack, line_number, line);
		free_grid(tokens);
		free(line);
		tokens = NULL;
		line = NULL;
		buflen = 0;
	}
	/*free_stack*/
	free_stack(stack);
	free(line);
	line = NULL;
	fclose(file);
	file = NULL;
	exit(0);
}
