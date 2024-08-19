#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * _setenv - Changes or adds an environment variable.
 * @name: The name of the environment variable.
 * @value: The value of the environment variable.
 * @overwrite: If non-zero, overwrite the existing variable.
 *
 * Return: 0 on success, -1 on error.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *new_env;
	size_t name_len, value_len, new_env_len;
	int i;

	if (name == NULL || value == NULL)
	{
		return -1;
	}

	name_len = strlen(name);
	value_len = strlen(value);
	new_env_len = name_len + 1 + value_len + 1;

	new_env = malloc(new_env_len);
	if (new_env == NULL)
	{
		perror("malloc");
		return -1;
	}

	snprintf(new_env, new_env_len, "%s=%s", name, value);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			if (overwrite)
			{
				free(environ[i]);
				environ[i] = new_env;
				return 0;
			}
			else
			{
				free(new_env);
				return 0;
			}
		}
	}

	/* Add new environment variable */
	int env_size = 0;
	while (environ[env_size] != NULL)
	{
		env_size++;
	}

	char **new_environ = malloc((env_size + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		perror("malloc");
		free(new_env);
		return -1;
	}

	for (i = 0; i < env_size; i++)
	{
		new_environ[i] = environ[i];
	}

	new_environ[env_size] = new_env;
	new_environ[env_size + 1] = NULL;

	environ = new_environ;

	return 0;
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
	if (ac != 4)
	{
		fprintf(stderr, "Usage: %s NAME VALUE OVERWRITE(0/1)\n", av[0]);
		return 1;
	}

	int overwrite = atoi(av[3]);
	if (_setenv(av[1], av[2], overwrite) == 0)
	{
		printf("Environment variable set successfully\n");
	}
	else
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}

	return 0;
}
