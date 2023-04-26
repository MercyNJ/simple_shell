#include "main.h"

/**
 * handle_exit - Exit shell with specified exit status.
 *
 * @argv: Pointer to string array containing command line arguments.
 *
 * Description: If exit status is inavalid,
 * An error message is printed to standard output.
 *
 * Return: Nothing.
 */

void handle_exit(char **argv)
{
	if (argv && argv[1])
	{
		int exit_status = atoi(argv[1]);

		if (exit_status == 0 || (exit_status > 0 && exit_status <= 255))
		{
			exit(exit_status);
		}
		else
		{
			printf("hsh: Exit: %s: Numeric argument needed\n", argv[1]);
			fflush(stdout);
		}
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
