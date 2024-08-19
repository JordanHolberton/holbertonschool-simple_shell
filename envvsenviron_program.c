#include "supershell.h"

/**
 * print_address - Prints the address of a variable.
 * @name: The name of the variable.
 * @addr: The address of the variable.
 */

void print_address(const char *name, void *addr)
{
	printf("%s: %p\n", name, addr);
}

/**
 * print_env_addresses - Prints the addresses of env and environ.
 * @env: The environment variables passed to main.
 */

void print_env_addresses(char **env)
{
	extern char **environ;

	print_address("Address of env", (void *)env);
	print_address("Address of environ", (void *)environ);
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

	print_env_addresses(env);
	return 0;
}
