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
			if (value == NULL) {
				perror("strdup");
				return NULL;
			}
			return value;
		}
	}

	return NULL;
}

/**
 * print_path_directories - Prints each directory in the PATH environment variable.
 */

void print_path_directories(void)
{
	char *path = _getenv("PATH");
	char *dir;

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return;
	}

	dir = strtok(path, ":");
	while (dir != NULL) {
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path);
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
	(void)ac; /* Unused parameter */
	(void)av; /* Unused parameter */

	print_path_directories();
	return 0;
}
