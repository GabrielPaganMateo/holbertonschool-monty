#include "monty.h"
/**
 * call_func - call the function for stack or queue manipulation
 * @tokens: tokens
 * Return: function
 */
void (*call_func(char **tokens))(stack_t **, unsigned int, char *, FILE *)
{
	int i = 0;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, invalid}
	};

	while (i < 8)
	{
		if (strcmp(tokens[0], functions[i].opcode) == 0)
		{
			return (functions[i].f);
		}
		i++;
		if (i == 7)
		{
			return (functions[i].f);
		}
	}
	return (NULL);
}

