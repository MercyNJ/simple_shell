#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void execution(char **argv);
char *get_path(char *user_command);
void handle_exit(char **argv);
void handle_env();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int set_env(char **envp, const char *name, const char *value, int overwrite);

#endif
