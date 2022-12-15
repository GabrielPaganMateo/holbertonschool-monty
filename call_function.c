#include "monty.h"
/**
 * function_call - call the function for stack or queue manipulation
 * @opcode: code operation
 * @number: number to be used
 * Return: nothing
 */
void (*call_function(char **tokens))(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	int i = 0;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, invalid}
	};

	while (i < 3)
	{
		if (strcmp(tokens[0], functions[i].opcode) == 0)
		{
			return (functions[i].f);
		}
		i++;
		/*if (i == 2)
		{
			return (functions[i].f);
		}
		*/
	}
	return (NULL);
}

