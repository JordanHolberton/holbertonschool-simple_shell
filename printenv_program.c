#include "supershell.h"
#include <stdio.h>

/**
 * print_environment - Prints the environment variables.
 */

void print_environment(void)
{
	extern char **environ;
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
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

	print_environment();
	return 0;
}
