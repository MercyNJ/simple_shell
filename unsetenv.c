#include "main.h"

int unset_env(char **envp, const char *name)
{
	char **env_var, **newenv_list;
	int i, j, env_found, count;

	count = 0;
	env_found = 0;

	if (name == NULL)
	{
		fprintf(stderr, "Error: Name cannot be NULL\n");
		return (1);
	}

	for (env_var = envp; *env_var != NULL; env_var++)
       	{ 
        count++;
    }

    newenv_list = (char **)malloc((count + 1) * sizeof(char *));
    if (newenv_list == NULL) { 
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1;
    }

	for (i = 0, j = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], name, strlen(name)) == 0 && envp[i][strlen(name)] == '=')
		{
			env_found = 1;
			continue;
		}
		newenv_list[j++] = envp[i];
	}

	newenv_list[j] = NULL;

	if (!env_found)
	{
		fprintf(stderr, "Error:Env variable not found\n");
		return (1);
	}
	environ = newenv_list;
	return (0);
}

