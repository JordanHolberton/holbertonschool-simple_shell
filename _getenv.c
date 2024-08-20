#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Custom implementation of getenv.
 * @name: Name of the environment variable to get.
 *
 * Return: Value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len;

	if (name == NULL)
		return (NULL);

	name_len = strlen(name);

	/* Loop through environment variables */
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
	}

	return (NULL);
}

