#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * handle_fork_error - Function to handle errors from fork
 */

void handle_fork_error()
{
	perror("Error:");
}

/**
 * child_process - Function to simulate child process work
 */

void child_process()
{
	printf("Wait for me, wait for me\n");
	sleep(3);
}

/**
 * parent_process - Function to simulate parent process work
 */

void parent_process(pid_t child_pid)
{
	/**
	 * Supress unused parameter warning
	 */
	(void)child_pid;
	int status;
	wait(&status);
	printf("Oh, it's all better now\n");
}

/**
 * Main function
 */

int main(void)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		handle_fork_error();
		return 1;
	}

	if (child_pid == 0)
	{
		/**
		 * Child process
		 */
		child_process();
	}
	else
	{
		/**
		 * Parent process
		 */
		parent_process(child_pid);
	}

	return 0;
}
