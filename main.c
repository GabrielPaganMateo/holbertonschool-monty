#include "monty.h"
#include "numberARG.h"
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
	char *token;
	char **tokens = malloc(sizeof(char*));
	int i = 0;

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
		token = strtok(line, " \n");
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			if (i >= 2)
			{
				i = i * 2;
				tokens = realloc(tokens, i * sizeof(char*));
			}
			token = strtok(NULL, " \n");
		}
		tokens[i] = NULL;
		num_arg = atoi(tokens[1]);
		call_function(tokens)(&stack, line_number);
	}
	fclose(file);
	return (0);
}
