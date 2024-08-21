#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the variable.
 *
 * Return: The value of the variable, or NULL if it does not exist.
 */
char *_getenv(const char *name)
{
	char **env = environ;
	size_t name_len = strlen(name);

	while (*env != NULL)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (*env + name_len + 1);
		env++;
	}
	return (NULL);
}

/**
 * find_command_path - Searches for a command in PATH directories.
 * @cmd: Command to search for.
 *
 * Return: Full path of the command if found, or NULL otherwise.
 */
char *find_command_path(char *cmd)
{
	char *path, *path_copy, *dir;
	char *full_path;
	struct stat st;

	if (access(cmd, X_OK) == 0)
		return (strdup(cmd));

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	full_path = malloc(1024);
	if (full_path == NULL)
	{
		free(path_copy);
		return (NULL);
	}

	dir = strtok(path_copy, ":");
	while (dir)
	{
		sprintf(full_path, "%s/%s", dir, cmd);
		if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(full_path);
	free(path_copy);
	return (NULL);
}

