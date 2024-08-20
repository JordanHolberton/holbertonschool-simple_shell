#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char **split_line(char *line);
int execute(char **args);
void print_env(void);
char *find_command_path(char *cmd);

#endif /* SHELL_H */

