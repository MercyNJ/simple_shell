#include "main.h"

/**
 * handle_env - Prints environment variables passed.
 *
 * @envp: String array containing environment variables to be printed.
 * Description: Prints each, one per line,to standard output.
 *
 * Return: Nothing.
 */

void handle_env(char **envp)
{

	char **env = envp;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
