#include "file.h"

/**
 * _feof - Checks the end-of-file indicator on a file stream.
 * @stream: The file stream to check.
 *
 * Return: 1 if the end-of-file indicator is set for the stream, 0 otherwise.
 */
int _feof(FILE *stream)
{
	return (stream->_flags & _IOEOF);
}

