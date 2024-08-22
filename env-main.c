#include "supershell.h"
#include <stdio.h>

/**
 * print_environment - Prints the environment variables.
 * @env: The environment variables.
 */
void print_environment(char **env)
{
	char **env_ptr = env;

	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
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

	path_node_t *path_list;

	path_node_t = build_path_list();
	if (path_list != NULL)
	{
		print_path_list(path_list);
		free_path_list(path_list);
	}

	char command[256];
	char *path;

	path = get_path();
	if (!path)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return 1;
	}

	while (1)
	{
		printf(":) ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		/* Remove newline character */
		command[strcspn(command, "\n")] = 0;

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		execute_command(command, path);
	}

	free(path);

	print_env_addresses(env);

	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	print_before_execve();

	if (execve(argv[0], argv, NULL) == -1)
	{
		handle_execve_error(argv[0]);
	}

	print_after_execve();

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

	const int num_children = 5;
	int i;
	pid_t child_pid;

	for (i = 0; i < num_children; i++)
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

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s ENV_VAR_NAME\n", av[0]);
		return 1;
	}

	char *value = _getenv(av[1]);
	if (value != NULL)
	{
		printf("%s=%s\n", av[1], value);
		free(value);
	}
	else
	{
		printf("%s: NOT FOUND\n", av[1]);
	}

		int id = fork();
	if (id == 0)
	{
		child_process();
	}
	else
	{
		parent_process(id);
	}


	if (argc < 2)
	{
		print_usage(argv[0]);
		return 1;
	}
	process_files(argc, argv);

	print_environment();

		while (1)
	{
		print_prompt();
		char *command = read_line();

		if (command == NULL)
		{
			/**
			 *  End-of-file (EOF) or error encountered
			 */
			break;
		}

		/**
		 *  Print the command
		 */
		printf("%s", command);

		/**
		 *  Free the allocated memory
		 */
		free(command);
	}

	if (ac != 4)
	{
		fprintf(stderr, "Usage: %s NAME VALUE OVERWRITE(0/1)\n", av[0]);
		return 1;
	}

	int overwrite = atoi(av[3]);
	if (_setenv(av[1], av[2], overwrite) == 0)
	{
		printf("Environment variable set successfully\n");
	}
	else
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}

	const char *str = "This is a test string";
	const char *delim = " ";
	int word_count = 0;
	int i;

	char **words = split_string(str, delim, &word_count);
	if (words == NULL)
	{
		fprintf(stderr, "Failed to split string\n");
		return 1;
	}

	/**
	 * Print the words
	 */
	for (i = 0; i < word_count; i++)
	{
		printf("Word %d: %s\n", i + 1, words[i]);
	}

	/**
	 * Free the allocated memory
	 */
	free_words(words, word_count);


	if (argc < 2)
	{
		print_usage(argv[0]);
		return 1;
	}
	process_files(argc, argv);

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
		for (size_t i = 0; command[i] != '\0'; i++)
		{
			if (command[i] == '\n')
			{
				command[i] = '\0';
				break;
			}
		}

		if (strlen(command) > 0)
		{
			execute_command(command);
		}

		/**
		 * Free the allocated memory
		 */
		free(command);
	}

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s NAME\n", av[0]);
		return 1;
	}

	if (_unsetenv(av[1]) == 0)
	{
		printf("Environment variable unset successfully\n");
	}
	else
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}

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

	return (0);
}
