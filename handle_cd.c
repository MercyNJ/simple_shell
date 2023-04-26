#include "main.h"

void my_cd(char *dir) {
    char *cwd = malloc(sizeof(char) * 1024);
    if (getcwd(cwd, 1024) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }

    if (dir == NULL || strcmp(dir, "~") == 0) {
        chdir(getenv("HOME"));
    }
    else if (strcmp(dir, "-") == 0) {
        chdir(getenv("OLDPWD"));
    }
    else {
        if (chdir(dir) == -1) {
            perror("chdir() error");
        }
    }

    if (getcwd(cwd, 1024) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }

    setenv("OLDPWD", cwd, 1);
    setenv("PWD", cwd, 1);
}
