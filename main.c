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

	/*define stack & head*/
	stack_t *stack = NULL;

	/*line_number*/
	static unsigned int line_number;

	/*new_line*/
	char *new_line = "\n";

	int checkLine = 1;

	line_number = 0;
	if (argc != 2)
		exit(EXIT_FAILURE);

	if (argv[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &buflen, file) != -1)
	{
		checkLine++;
		if (strcmp(line, new_line) == 0)
		{
			continue;
		}
		if (check_line(line) == 0)
		{
			continue;
		}
		line_number++;
		tokens = tokenization(line, " \n");
		/*if (tokens[0] == NULL)
		{
			free(line);
			free_grid(tokens);
			tokens = NULL;
			line = NULL;
			buflen = 0;
			continue;
		}*/
		call_function(tokens)(&stack, line_number, line, file);
		free_grid(tokens);
		free(line);
		tokens = NULL;
		line = NULL;
		buflen = 0;
	}
	free_stack(stack);
	free(line);
	line = NULL;
	fclose(file);
	file = NULL;
	exit(0);
}
