#include "header.h"
/**
 * main - main function of monty program, accepts command for updating
 * stacks & queues
 */
int main(int argc, char **argv)
{
	int fd, count = INT_MAX;
	char *line = NULL;
	FILE *file = NULL;
	size_t buflen = 0;

	if (argc != 2)
		return (EXIT_FAILURE);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);

	read(fd, file, count);

	getline(&line, &buflen, file);



}
