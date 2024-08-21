#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated string, or NULL if it fails.
 */
char *_strdup(const char *str)
{
    char *dup;
    size_t len = 0;

    while (str[len])
        len++;

    dup = malloc(len + 1);
    if (dup == NULL)
        return (NULL);

    for (len = 0; str[len]; len++)
        dup[len] = str[len];
    dup[len] = '\0';

    return (dup);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the variable.
 *
 * Return: The value of the variable, or NULL if it does not exist.
 */
char *_getenv(const char *name)
{
    size_t len;
    char **env = environ;

    for (len = 0; name[len]; len++)
        ;

    while (*env)
    {
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
            return (*env + len + 1);
        env++;
    }

    return (NULL);
}

/**
 * _sprintf - Simplified version of snprintf.
 * @buffer: The buffer to write to.
 * @format: The format string.
 * @dir: The directory path.
 * @cmd: The command name.
 *
 * Return: The number of characters written.
 */
int _sprintf(char *buffer, const char *format, const char *dir, const char *cmd)
{
    char *buf_ptr = buffer;

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 's')
        {
            while (*dir)
                *buf_ptr++ = *dir++;
            dir = cmd;
            format += 2;
        }
        else
        {
            *buf_ptr++ = *format++;
        }
    }

    *buf_ptr = '\0';
    return (buf_ptr - buffer);
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
        return _strdup(cmd);

    path = _getenv("PATH");
    if (path == NULL)
        return (NULL);

    path_copy = _strdup(path);
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
        _sprintf(full_path, "%s/%s", dir, cmd);
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

