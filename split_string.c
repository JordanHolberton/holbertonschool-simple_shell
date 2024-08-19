#include "supershell.h"

/**
 * Function to split a string into words
 */

char** split_string(const char *str, const char *delim, int *word_count)
{
	/**
	 * Make a copy of the input string to avoid modifying the original
	 */

	char *str_copy = strdup(str);
	if (str_copy == NULL)
	{
		perror("strdup");
		return NULL;
	}

	/**
	 * Allocate an initial array of pointers to store words
	 */

	char **words = malloc(sizeof(char*));
	if (words == NULL)
	{
		perror("malloc");
		free(str_copy);
		return NULL;
	}

	/**
	 * Tokenize the string
	 */

	char *token = strtok(str_copy, delim);
	int count = 0;

	while (token != NULL)
	{
		/**
		 * Allocate memory for the current word
		 */
		words[count] = strdup(token);
		if (words[count] == NULL)
		{
			perror("strdup");
			/**
			 * Free previously allocated words and the string copy
			 */
			for (int i = 0; i < count; i++)
			{
				free(words[i]);
			}
			free(words);
			free(str_copy);
			return NULL;
		}

		/**
		 * Move to the next token
		 */
		token = strtok(NULL, delim);
		count++;

		/**
		 * Reallocate the words array to accommodate the new word
		 */
		words = realloc(words, (count + 1) * sizeof(char*));
		if (words == NULL)
		{
			perror("realloc");
			/**
			 * Free previously allocated words and the string copy
			 */
			for (int i = 0; i < count; i++)
			{
				free(words[i]);
			}
			free(str_copy);
			return NULL;
		}
	}

	/**
	 * Set the word count
	 */
	*word_count = count;

	/**
	 * Free the string copy
	 */
	free(str_copy);

	return words;
}

/**
 * Function to free the array of words
 */

void free_words(char **words, int word_count)
{
	for (int i = 0; i < word_count; i++)
	{
		free(words[i]);
	}
	free(words);
}

/**
 * Main function for testing
 */

int main()
{
	const char *str = "This is a test string";
	const char *delim = " ";
	int word_count = 0;

	char **words = split_string(str, delim, &word_count);
	if (words == NULL)
	{
		fprintf(stderr, "Failed to split string\n");
		return 1;
	}

	/**
	 * Print the words
	 */
	for (int i = 0; i < word_count; i++)
	{
		printf("Word %d: %s\n", i + 1, words[i]);
	}

	/**
	 * Free the allocated memory
	 */
	free_words(words, word_count);

	return 0;
}
