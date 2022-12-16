#include "monty.h"
/**
 * check_line - checks if line is empty
 * @line: pointer to line
 * Return: 0 if line is empty, 1 if line is not empty
 */
int check_line(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] >= 97 && line[i] <= 122)
		{
			return (1);
		}
		if (line[i] >= 65 && line[i] <= 90)
		{
			return (1);
		}
		i++;
	}

	return (0);
}
