#ifndef SUPERSHELL_H
#define SUPERSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/**
 * Structure definition of path_node_t
 */

typedef struct path_node
{
	char *dir;
	struct path_node *next;
} path_node_t;

/**
 * Main declaration
 */

int main(int ac, char **av);

/**
 * Declaration protos
 */

int _setenv(const char *name, const char *value, int overwrite);
int check_file_status(const char *file_path);
int _unsetenv(const char *name);

void print_usage(const char *program_name);
void print_arguments(char **av);
void print_path_list(path_node_t *head);
void free_path_list(path_node_t *head);
void print_path_directories(void);
void print_environment(char **env);
void print_address(const char *name, void *addr);
void print_env_addresses(char **env);
void print_before_execve();
void print_after_execve();
void handle_execve_error(const char *program_name);
void print_before_fork();
void print_after_fork();
void handle_fork_error();
void print_pid(pid_t pid, const char *process_type);
void child_process();
void parent_process(pid_t child_pid);
void print_process_info(const char* process_type);
void parent_process(int child_id);
void process_files(int argc, char *argv[]);
void print_prompt();
void free_words(char **words, int word_count);
void execute_command(char *command);


char *_getenv(const char *name);
char *get_path(void);
char *check_file_in_dir(const char *dir, const char *filename);
char *find_file_in_path(const char *path, const char *filename);
char* read_line();
char** split_string(const char *str, const char *delim, int *word_count);


path_node_t *create_path_node(const char *dir);
path_node_t *build_path_list(void);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
