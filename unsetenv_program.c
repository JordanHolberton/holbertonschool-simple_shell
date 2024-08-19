#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _unsetenv - Deletes an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: 0 on success, -1 on error.
 */

int _unsetenv(const char *name)
{
	extern char **environ;
	size_t name_len;
	int i, j;

	if (name == NULL || environ == NULL)
	{
		return -1;
	}

	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			free(environ[i]);
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			return 0;
		}
	}

	return -1;
}

/**
 * main - Entry point of the program.
 * @ac: The number of arguments.
 * @av: The list of arguments.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s NAME\n", av[0]);
		return 1;
	}

	if (_unsetenv(av[1]) == 0)
	{
		printf("Environment variable unset successfully\n");
	}
	else
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}

	return 0;
}
