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
 * handle_execve_error - Function to handle errors from execve
 */

void handle_execve_error(const char *program_name)
{
	perror("Error:");
	fprintf(stderr, "Failed to execute %s\n", program_name);
}

/**
 * child_process - Function to simulate child process work
 */

void child_process()
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	if (execve(argv[0], argv, NULL) == -1)
	{
		handle_execve_error(argv[0]);
	}
}

/**
 * parent_process - Function to simulate parent process work
 */

void parent_process(pid_t child_pid)
{
	int status;
	wait(&status);
	printf("Child process with PID %d exited with status %d\n", child_pid, WEXITSTATUS(status));
}

/**
 * Main function
 */

int main(void)
{
	const int num_children = 5;

	for (int i = 0; i < num_children; i++)
	{
		pid_t child_pid = fork();
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
	}

	return 0;
}
