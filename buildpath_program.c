#include "supershell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char *env_var;
	char *value;
	size_t name_len;
	int i;

	if (name == NULL || environ == NULL)
	{
		return NULL;
	}

	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];

		if (strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
		{
			value = strdup(env_var + name_len + 1);
			if (value == NULL)
			{
				perror("strdup");
				return NULL;
			}
			return value;
		}
	}

	return NULL;
}

/**
 * create_path_node - Creates a new node for the linked list.
 * @dir: The directory path.
 *
 * Return: Pointer to the new node, or NULL if memory allocation fails.
 */

path_node_t *create_path_node(const char *dir)
{
	path_node_t *new_node = malloc(sizeof(path_node_t));
	if (new_node == NULL)
	{
		perror("malloc");
		return NULL;
	}

	new_node->dir = strdup(dir);
	if (new_node->dir == NULL)
	{
		perror("strdup");
		free(new_node);
		return NULL;
	}

	new_node->next = NULL;
	return new_node;
}

/**
 * build_path_list - Builds a linked list of the PATH directories.
 *
 * Return: Pointer to the head of the linked list, or NULL if memory allocation fails.
 */

path_node_t *build_path_list(void)
{
	char *path = _getenv("PATH");
	path_node_t *head = NULL;
	path_node_t *current = NULL;
	char *dir;

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return NULL;
	}

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		path_node_t *new_node = create_path_node(dir);
		if (new_node == NULL)
		{
			/* Free previously allocated nodes if memory allocation fails */
			while (head != NULL)
			{
				current = head;
				head = head->next;
				free(current->dir);
				free(current);
			}
			free(path);
			return NULL;
		}

		if (head == NULL)
		{
			head = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}

		dir = strtok(NULL, ":");
	}

	free(path);
	return head;
}

/**
 * print_path_list - Prints the linked list of PATH directories.
 * @head: Pointer to the head of the linked list.
 */

void print_path_list(path_node_t *head)
{
	path_node_t *current = head;
	while (current != NULL)
	{
		printf("%s\n", current->dir);
		current = current->next;
	}
}

/**
 * free_path_list - Frees the linked list of PATH directories.
 * @head: Pointer to the head of the linked list.
 */

void free_path_list(path_node_t *head)
{
	path_node_t *current = head;
	path_node_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->dir);
		free(current);
		current = next;
	}
}

/**
 * main - Entry point of the program.
 * @ac: The number of arguments.
 * @av: The list of arguments.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	(void)ac; /* Unused parameter */
	(void)av; /* Unused parameter */

	path_node_t *path_list;
	path_node_t = build_path_list();
	if (path_list != NULL)
	{
		print_path_list(path_list);
		free_path_list(path_list);
	}

	return 0;
}
