#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * print_usage - Prints the usage of the program.
 * @program_name: The name of the program.
 */

void print_usage(const char *program_name)
{
	printf("Usage: %s path_to_file ...\n", program_name);
}

/**
 * check_file_status - Checks the status of a file.
 * @file_path: The path to the file.
 *
 * Return: 0 if the file is found, 1 otherwise.
 */

int check_file_status(const char *file_path)
{
	struct stat st;
	if (stat(file_path, &st) == 0)
	{
		printf("%s: FOUND\n", file_path);
		return 0;
	}
	else
	{
		printf("%s: NOT FOUND\n", file_path);
		return 1;
	}
}

/**
 * process_files - Processes the list of files.
 * @argc: The number of arguments.
 * @argv: The list of arguments.
 */

void process_files(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		check_file_status(argv[i]);
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
