#include <stdio.h>
#include <stdlib.h>

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
