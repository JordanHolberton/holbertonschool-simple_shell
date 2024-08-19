#include "shell.h"

int shell_cd(char **args);
int shell_exit(char **args);

char *builtin_str[] = {
	"cd",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&shell_cd,
	&shell_exit
};

/**
 * num_builtins - return intern commands
 * Return: number of intern commands
 */
int num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * shell_cd - change directory
 * @args: arguments list
 * Return: 1 (to continue the execution)
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * shell_exit - leave the shell
 * @args: arguments list
 * Return: Always 0
 */
int shell_exit(char **args)
{
	(void)args;
	return (0);
}
