#include "supershell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  Custom implementation of getline
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			size_t new_size = *n * 2;
			char *new_ptr = (char *)realloc(*lineptr, new_size);
			if (new_ptr == NULL)
			{
				return -1;
			}
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
		{
			break;
		}
	}

	if (pos == 0 && c == EOF)
	{
		return -1;
	}

	(*lineptr)[pos] = '\0';
	return pos;
}

/**
 *  Function to print the prompt
 */

void print_prompt()
{
	printf("$ ");
}

/**
 *  Function to read a line from the user
 */

char* read_line()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1) {
		/**
		 *  Free the allocated memory if getline fails
		 */
		free(line);
		line = NULL;
	}

	return line;
}

/**
 *  Main function
 */

int main()
{
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

	return 0;
}
