#include "shell.h"

/**
 * _feof - Checks the end-of-file indicator on a file stream.
 * @stream: The file stream to check.
 *
 * Return: 1 if the end-of-file indicator is set for the stream, 0 otherwise.
 */
int _feof(FILE *stream)
{
	int c = fgetc(stream);

	if (c == EOF) {
		if (feof(stream))
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}

	ungetc(c, stream);
	return (0);
}
