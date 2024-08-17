#include "shell.h"

/**
 * error_printing - Prints an error message using perror.
 * @msg: The message to print.
 *
 * Return: This function does not return a value (void).
 */
void error_printing(char *msg)
{
	perror(msg);
}

char *str_concat(char *s1, char *s2)
{
	char *result;
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);

	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);
	return (result);
}

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
