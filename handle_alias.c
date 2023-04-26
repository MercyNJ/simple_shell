#include "main.h"

#define MAX_ARGS 1024


char** handle_alias(char** argv)
{
    int i, j;
    char* name;
    char* value;
    char* alias_name;
    char* alias_value;
    char** alias_args;
    int found;
    int len;
    int name_len;
    int value_len;
    char* alias;
    char* alias_list[] = {"alias_name=alias_value", NULL};
   /* char** alias_list;*/

    if (argv[1] == NULL) {
        for (i = 0; alias_list[i] != NULL; i++) {
            name = strtok(alias_list[i], "=");
            value = strtok(NULL, "=");
            printf("%s='%s'\n", name, value);
        }
        return NULL;
    }

    for (i = 1; argv[i] != NULL; i++) {
        name = strtok(argv[i], "=");
        value = strtok(NULL, "=");
        if (value == NULL) {
            for (j = 0; alias_list[j] != NULL; j++) {
                alias_name = strtok(alias_list[j], "=");
                alias_value = strtok(NULL, "=");
                if (strcmp(alias_name, name) == 0) {
                    alias_args = (char**) malloc(sizeof(char*) * (MAX_ARGS));
                    alias_args[0] = alias_value;
                    alias_args[1] = NULL;
                    return alias_args;
                }
            }
        } else {
            name_len = strlen(name);
            value_len = strlen(value);
            alias = (char*) malloc(name_len + value_len + 4);
            sprintf(alias, "%s='%s'", name, value);
            found = 0;
            for (j = 0; alias_list[j] != NULL; j++) {
                alias_name = strtok(alias_list[j], "=");
                if (strcmp(alias_name, name) == 0) {
                    alias_list[j] = alias;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                len = 0;
                while (alias_list[len] != NULL) {
                    len++;
                }
                alias_list[len] = alias;
                alias_list[len + 1] = NULL;
            }
        }
    }

    return NULL;
}
