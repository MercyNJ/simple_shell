#include "main.h"

/**
 * get_next_command - Get next command from command
 * line arguments.
 *
 * @argv: Pointer to string array with command,
 * line arguments.
 *
 * Description: Searches for && or || in array,returns
 * a pinter to start of next command.
 *
 * Return: Pointer to next command
 */


char **get_next_command(char **argv)
{
	char **next_argv = argv;

	while (*next_argv != NULL && strcmp(*next_argv, "&&") != 0
&& strcmp(*next_argv, "||") != 0)
	{
		next_argv++;
	}

	if (*next_argv != NULL)
	{
		*next_argv = NULL;
		next_argv++;
	}

	return (next_argv);
}
