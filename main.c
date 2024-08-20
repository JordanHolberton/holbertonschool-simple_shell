#include "shell.h"

/**
 * main - Entry point for the simple shell.
 *
 * Return: 0 on success, or exit status on failure.
 */
int main(void)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	ssize_t nread;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		args = split_line(line);
		status = execute(args);
		free(args);
	}

	free(line);
	return (EXIT_SUCCESS);
}

