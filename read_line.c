#include "shell.h"

char *allocate_buffer(size_t bufsize);
void handle_read_error(char *buffer);
char *resize_buffer(char *buffer, size_t *bufsize);

/**
 * read_line - Reads a line from standard input.
 * This function uses 'read' to manually read a complete line.
 *
 * Return: The line read from stdin.
 */
char *read_line(void)
{
	size_t bufsize = 1024, position = 0;
	char *buffer = allocate_buffer(bufsize);
	int c;

	while (1)
	{
		c = read(STDIN_FILENO, &buffer[position], 1);
		if (c == -1)
			handle_read_error(buffer);
		else if (c == 0)
		{
			if (position == 0)
				exit(EXIT_SUCCESS);
			break;
		}
		else if (buffer[position++] == '\n')
			break;

		if (position >= bufsize)
			buffer = resize_buffer(buffer, &bufsize);
	}

	buffer[position] = '\0';
	return (buffer);
}

/**
 * allocate_buffer - Allocates a buffer for reading input.
 * @bufsize: The initial size of the buffer to allocate.
 *
 * Return: A pointer to the allocated buffer.
 */
char *allocate_buffer(size_t bufsize)
{
	char *buffer = malloc(bufsize);

	if (!buffer)
	{
		perror("Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}
	return (buffer);
}

/**
 * handle_read_error - Handles errors during reading from stdin.
 * @buffer: The buffer to free before exiting.
 *
 * Return: This function does not return as it exits the program.
 */
void handle_read_error(char *buffer)
{
	perror("read");
	free(buffer);
	exit(EXIT_FAILURE);
}

/**
 * resize_buffer - Resizes the buffer when more space is needed.
 * @buffer: The current buffer to resize.
 * @bufsize: A pointer to the current buffer size, which will be updated.
 *
 * Return: A pointer to the resized buffer.
 */
char *resize_buffer(char *buffer, size_t *bufsize)
{
	*bufsize += 1024;
	buffer = realloc(buffer, *bufsize);
	if (!buffer)
	{
		perror("Unable to reallocate buffer");
		exit(EXIT_FAILURE);
	}
	return (buffer);
}

