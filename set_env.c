#include "main.h"

int set_env(char **envp, const char *name, const char *value, int overwrite)
{
	 char **ptr;
	 size_t envp_len;
	 char *new_envp;
	 size_t entry_len;


    if (name == NULL || value == NULL)
    {
        fprintf(stderr, "Error: Name and value must not be NULL\n");
        return 1;
    }

    envp_len = strlen(name);
    for (ptr = envp; *ptr != NULL; ptr++)
    {
        if (strncmp(*ptr, name, envp_len) == 0 && (*ptr)[envp_len] == '=')
        {
            if (!overwrite)
            {
                return 0;
            }

            new_envp = malloc(envp_len + strlen(value) + 2);
            sprintf(new_envp, "%s=%s", name, value);
            *ptr = new_envp;
            return 0;
        }
    }

    entry_len = envp_len + strlen(value) + 2;
    new_envp = malloc(entry_len);
    sprintf(new_envp, "%s=%s", name, value);
    printf("%s", new_envp);

    for (ptr = envp; *ptr != NULL; ptr++)
    {
    	*ptr = new_envp;
    	*(ptr + 1) = NULL;
    }

    return 0;
}

