#include "shell.h"

/**
 * read_line - Reads a line from standard input.
 * This function use 'getline' to read a complete line
 *
 * Return: line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (_feof(stdin))
		{
			exit(EXIT_SUCCESS); /* Sortie en cas de EOF */
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
