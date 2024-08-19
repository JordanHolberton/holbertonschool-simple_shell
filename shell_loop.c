#include "shell.h"

/**
 * shell_loop - Shell main loop.
 * This function displays a prompt
 *
 * Return: nothing (void).
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		if (isatty(STDIN_FILENO))
			printf("$ "); /* Prompt */
		
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}
