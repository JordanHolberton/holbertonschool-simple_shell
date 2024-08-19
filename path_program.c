#include "supershell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * print_usage - Prints the usage of the program.
 * @program_name: The name of the program.
 */

void print_usage(const char *program_name)
{
	printf("Usage: %s filename ...\n", program_name);
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
 * process_files - Processes the list of files to find in the PATH.
 * @argc: The number of arguments.
 * @argv: The list of arguments.
 */

void process_files(int argc, char *argv[])
{
	char *path, *full_path;

	path = get_path();
	if (!path)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return;
	}

	for (int i = 1; i < argc; i++)
	{
		full_path = find_file_in_path(path, argv[i]);
		if (full_path)
		{
			printf("%s\n", full_path);
			free(full_path);
		}
		else
		{
			printf("%s: NOT FOUND\n", argv[i]);
		}
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
