#include "supershell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_before_execve -  Function to print a message before calling execve
 */

void print_before_execve()
{
	printf("Before execve\n");
}

/**
 * print_after_execve - Function to print a message after calling execve
 */

void print_after_execve()
{
	printf("After execve\n");
}

/**
 * handle_execve_error - Function to handle errors from execve
 */

void handle_execve_error(const char *program_name)
{
	perror("Error:");
	fprintf(stderr, "Failed to execute %s\n", program_name);
}

/**
 * Main function
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	print_before_execve();

	if (execve(argv[0], argv, NULL) == -1)
	{
		handle_execve_error(argv[0]);
	}

	print_after_execve();

	return 0;
}
