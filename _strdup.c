#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - Custom implementation of strdup.
 * @str: String to duplicate.
 *
 * Return: Pointer to the duplicated string or NULL on failure.
 */
char *_strdup(const char *str)
{
	size_t len;
	char *dup;
	size_t i;

	if (str == NULL)
		return (NULL);

	len = strlen(str);
	dup = (char *)malloc(len + 1); /* +1 for the null terminator */
	if (dup == NULL)
		return (NULL);

	/* Copy the string */
	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}

