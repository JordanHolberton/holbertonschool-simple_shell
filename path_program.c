#include "supershell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * print_usage - Prints the usage of the program.
 * @program_name: The name of the program.
 */

void print_usage(const char *program_name)
{
	printf("Usage: %s\n", program_name);
}

/**
 * get_path - Gets the PATH environment variable.
 *
 * Return: The PATH environment variable or NULL if not found.
 */

char *get_path(void)
{
	return getenv("PATH");
}

/**
 * check_file_in_dir - Checks if a file exists in a directory.
 * @dir: The directory to check.
 * @filename: The name of the file to check.
 *
 * Return: The full path to the file if found, NULL otherwise.
 */

char *check_file_in_dir(const char *dir, const char *filename)
{
	char *full_path;
	struct stat st;

	full_path = malloc(strlen(dir) + strlen(filename) + 2);
	if (!full_path)
	{
		perror("malloc");
		return NULL;
	}

	sprintf(full_path, "%s/%s", dir, filename);
	if (stat(full_path, &st) == 0)
	{
		return full_path;
	}

	free(full_path);
	return NULL;
}

/**
 * find_file_in_path - Finds a file in the PATH directories.
 * @path: The PATH environment variable.
 * @filename: The name of the file to find.
 *
 * Return: The full path to the file if found, NULL otherwise.
 */

char *find_file_in_path(const char *path, const char *filename)
{
	char *path_copy, *dir;
	char *full_path = NULL;

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		return NULL;
	}

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = check_file_in_dir(dir, filename);
		if (full_path)
		{
			break;
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return full_path;
}

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 * @path: The PATH environment variable.
 */

void execute_command(const char *command, const char *path)
{
	char *full_path = find_file_in_path(path, command);
	if (full_path)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			/* Child process */
			execl(full_path, command, (char *)NULL);
			perror("execl");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			/* Parent process */
			wait(NULL);
		}
		else
		{
			perror("fork");
		}
		free(full_path);
	}
	else
	{
		printf("%s: command not found\n", command);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: The list of arguments.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_usage(argv[0]);
		return 1;
	}
	process_files(argc, argv);
	return 0;
}
