#include "shell.h"

/**
 * find_command_path - Searches for a command in PATH directories.
 * @cmd: Command to search for.
 *
 * Return: Full path of the command if found, NULL otherwise.
 */
char *find_command_path(char *cmd)
{
    char *path, *path_copy, *dir;
    char *full_path;
    int len;

    path = getenv("PATH");
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
        len = snprintf(full_path, 1024, "%s/%s", dir, cmd);
        if (len >= 0 && access(full_path, X_OK) == 0)
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

