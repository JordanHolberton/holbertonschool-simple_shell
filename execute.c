#include "shell.h"

/**
 * execute - Executes a command by forking a new process.
 * @args: Null-terminated array of arguments.
 *
 * Return: 1 to continue execution, 0 to exit.
 */
int execute(char **args)
{
    pid_t pid;
    int status;
    char *command_path;

    if (args[0] == NULL)
        return (1);

    if (strcmp(args[0], "exit") == 0)
        return (0);

    command_path = find_command_path(args[0]);
    if (command_path == NULL)
    {
        fprintf(stderr, "hsh: %s: command not found\n", args[0]);
        return (1);
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(command_path, args, environ) == -1)
            perror("hsh");
        _exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("hsh");
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(command_path);
    return (1);
}

