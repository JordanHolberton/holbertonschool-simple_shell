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
	int i;

	for (i = 1; av[i] !=NULL; i++)
	{
	printf("Argument %d: %s\n", i, av[i]);
	}
}
