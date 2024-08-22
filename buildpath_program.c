#include "supershell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
				fprintf(stderr, "Error: strdup failed\n");
				return NULL;
			}
			return value;
		}
	}

	return NULL;
}

path_node_t *create_path_node(const char *dir)
{
	path_node_t *new_node = malloc(sizeof(path_node_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return NULL;
	}

	new_node->dir = strdup(dir);
	if (new_node->dir == NULL)
	{
		fprintf(stderr, "Error: strdup failed\n");
		free(new_node);
		return NULL;
	}

	new_node->next = NULL;
	return new_node;
}

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

void print_path_list(path_node_t *head)
{
	path_node_t *current = head;
	while (current != NULL)
	{
		printf("%s\n", current->dir);
		current = current->next;
	}
}

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
