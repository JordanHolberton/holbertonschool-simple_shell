#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * print_before_fork - Function to print a message before calling fork
 */

void print_before_fork()
{
	printf("Before fork\n");
}

/**
 * print_after_fork -  Function to print a message after calling fork
 */

void print_after_fork()
{
	printf("After fork\n");
}

/**
 * handle_fork_error - Function to handle errors from fork
 */

void handle_fork_error()
{
	perror("Error:");
}

/**
 * print_pid - Function to print the process ID
 */

void print_pid(pid_t pid, const char *process_type)
{
	printf("%s pid id %u\n", process_type, pid);
}

/**
 * Main function
 */

int main(void)
{
	pid_t my_pid;
	pid_t pid;

	print_before_fork();

	pid = fork();
	if (pid == -1)
	{
		handle_fork_error();
		return 1;
	}

	print_after_fork();

	my_pid = getpid();
	if (pid == 0)
	{
		/**
		 * child process
		 */
		print_pid(my_pid, "Child");
	}
	else
	{
		/**
		 * parent process
		 */
		print_pid(my_pid, "Parent");
	}

	return 0;
}
