#include "main.h"


void handle_env(char **envp)
{

	char **env = envp;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
