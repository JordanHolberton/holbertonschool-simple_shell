#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

void error_printing(char *msg);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);

#endif
