#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char *env_var;
	char *value;
	size_t name_len;

	if (name == NULL || environ == NULL)
	{
		return NULL;
	}

	name_len = strlen(name);

	for (int i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];

		if (strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
		{
			value = strdup(env_var + name_len + 1);
			if (value == NULL)
			{
				perror("strdup");
				return NULL;
			}
			return value;
		}
	}

	return NULL;
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
		fprintf(stderr, "Usage: %s ENV_VAR_NAME\n", av[0]);
		return 1;
	}

	char *value = _getenv(av[1]);
	if (value != NULL)
	{
		printf("%s=%s\n", av[1], value);
		free(value);
	}
	else
	{
		printf("%s: NOT FOUND\n", av[1]);
	}

	return 0;
}
