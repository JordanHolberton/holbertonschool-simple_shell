#include "supershell.h"

/**
 * print_environment - Prints the environment variables.
 * @env: The environment variables.
 */

void print_environment(char **env)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * main - Entry point of the program.
 * @ac: The number of arguments.
 * @av: The list of arguments.
 * @env: The environment variables.
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	(void)ac; /* Unused parameter */
	(void)av; /* Unused parameter */

	print_environment(env);
	return 0;
}
