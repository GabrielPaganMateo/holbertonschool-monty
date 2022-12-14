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
	static int line_number = 0;

	/*atoi int*/

	/*Push string*/
	char *PUSH = "push";

	if (argc != 2)
		exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");

	while (getline(&line, &buflen, file) != -1)
	{
		token = strtok(line, " \n");
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			line_number++;
			if (i >= 2)
			{
				i = i * 2;
				tokens = realloc(tokens, i * sizeof(char*));
			}
			token = strtok(NULL, " \n");
		}
		tokens[i] = NULL;
		printf("%s ", tokens[0]);
		if (strcmp(tokens[0], PUSH) == 0)
		{
			printf("%s\n", tokens[1]);
			num_arg = atoi(tokens[1]);
			push(&stack);
		}
	}
	printf("\n");
	pall(stack);

	fclose(file);
	return (0);
}
