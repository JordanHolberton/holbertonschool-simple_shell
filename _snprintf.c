#include "shell.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

/**
 * _snprintf - Custom implementation of snprintf.
 * @buf: Buffer to store the formatted string.
 * @size: Maximum number of bytes to write to the buffer.
 * @format: Format string.
 * @...: Values to format.
 *
 * Return: Number of characters that would have been written.
 */
int _snprintf(char *buf, size_t size, const char *format, ...)
{
	va_list args;
	int written;
	char temp[BUF_SIZE];

	if (buf == NULL || format == NULL)
		return (-1);

	va_start(args, format);
	written = vsnprintf(temp, BUF_SIZE, format, args);
	va_end(args);

	if (written < 0)
		return (-1);

	if ((size_t)written >= size)
		written = size - 1;

	memcpy(buf, temp, written);
	buf[written] = '\0';

	return (written);
}

