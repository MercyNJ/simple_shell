#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 1024
#define NO_OPERATOR [1024] = {0}; 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;
extern bool success;


void execution(char **argv);
char *get_path(char *user_command);
void handle_exit(char **argv);
void handle_env();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int set_env(char **envp, const char *name, const char *value, int overwrite);
int unset_env(char **envp, const char *name);
void my_cd(char *dir);
bool handle_logic(char **argv);
void comments(char *lineptr);
char** handle_alias(char** argv);
char **get_next_command(char **argv);

#endif
