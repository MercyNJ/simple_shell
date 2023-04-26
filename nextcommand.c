#include "main.h"

char **get_next_command(char **argv)
{
    char **next_argv = argv;

    while (*next_argv != NULL && strcmp(*next_argv, "&&") != 0 && strcmp(*next_argv, "||") != 0)
    {
        next_argv++;
    }

    if (*next_argv != NULL)
    {
        *next_argv = NULL;
        next_argv++;
    }

    return next_argv;
}
