#include "shell.h"

/**
 * execute - create a children processus for execute a program.
 * She create a new process with 'fork()'
 * Execute it with 'waitpid()', 'fork()' or 'execvp()'
 * @args: List of arguments passed to the command
 *
 * Return: 1 to continue shell execution.
 */

int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	if (args[0] == NULL)
		return (1);

	pid = fork();
	if (pid == -1)
	{
		perror("hsh");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (wpid == -1 && errno == EINTR);

		if (wpid == -1)
		{
			perror("waitpid");
			return (1);
		}
	}
	return (1);
}
