#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * print_prompt - Function to print the shell prompt
 */

void print_prompt()
{
	printf("$ ");
}

/**
 * read_line - Function to read a line from the user
 */

char* read_line()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		/**
		 * Free the allocated memory if getline fails
		 */
		free(line);
		line = NULL;
	}

	return line;
}

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
 * execute_command - Function to execute a command
 */

void execute_command(char *command)
{
	pid_t child_pid = fork();
	if (child_pid == -1)
	{
		handle_fork_error();
		return;
	}

	if (child_pid == 0)
	{
		/**
		 * Child process
		 */
		char *argv[] = {command, NULL};
		if (execve(command, argv, NULL) == -1)
		{
			handle_execve_error(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/**
		 * Parent process
		 */
		int status;
		wait(&status);
		printf("Command %s exited with status %d\n", command, WEXITSTATUS(status));
	}
}

/**
 * Main function
 */

int main(void)
{
	while (1)
	{
		print_prompt();
		char *command = read_line();

		if (command == NULL)
		{
			/**
			 * End-of-file (EOF) or error encountered
			 */
			break;
		}

		/**
		 * Remove the newline character from the command
		 */
		command[strcspn(command, "\n")] = 0;

		if (strlen(command) > 0)
		{
			execute_command(command);
		}

		/**
		 * Free the allocated memory
		 */
		free(command);
	}

	return 0;
}
