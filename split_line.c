#include "shell.h"

/**
 * split_line - Split a line into tokens (arguments).
 * @line: The line to split.
 *
 * Return: Null-terminated array of tokens.
 */
char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		if (position < bufsize)
		{
			tokens[position++] = token;
		}
		else
		{

			break;
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
