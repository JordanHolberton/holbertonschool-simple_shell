#include <stdio.h>
#include "supershell.h"

/**
 * Function to print usage information
 */

void print_usage(const char *program_name)
{
	printf("Usage: %s [arguments...]\n", program_name);
}

/**
 * Function to print all arguments
 */

void print_arguments(char **av)
{
	printf("Arguments:\n");
	while (*av != NULL)
	{
		printf("%s\n", *av);
		av++;
	}
}

/**
 * Main function
 */

int main(int ac, char **av)
{
	/**
	 * supress unused parameter warning
	 */
	(void)ac;

	/**
	 * Check if no arguments are provided
	 */
	if (av[1] == NULL)
	{
		print_usage(av[0]);
		return 1;
	}

	/**
	 * Print all arguments
	 */
	print_arguments(av);

	return 0;
}
