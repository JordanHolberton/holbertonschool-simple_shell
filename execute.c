#include "shell.h"

/**
 * execute - Execute a command.
 * @args: Null-terminated array of arguments.
 *
 * Return: 1 to continue execution, 0 to exit.
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	if (strcmp(args[0], "exit") == 0)
		return (0);
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
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

	return (1);
}

