#include "main.h"

/**
 * handle_logic - Handles logic operators && and ||,
 * in the command line arguments.
 *
 * @argv: Pointer to string array with command 
 * line arguments.
 *
 * Description: If && is found,next command executed only,
 * if previous was successful.
 *
 * Return: Boolean value.
 */

bool handle_logic(char **argv)
{
	bool success = true; 
	bool short_circuit = false;

	while (*argv != NULL)
	{
		if (strcmp(*argv, "&&") == 0)
		{
			argv++;
		if (*argv != NULL && !short_circuit)
		{
			success = execution(argv);
			if (!success)
			{
				short_circuit = true;
			}
		}
		}
		else if (strcmp(*argv, "||") == 0)
		{
			argv++;
		if (*argv != NULL && !short_circuit)
		{
			success = execution(argv);
			if (success)
			{
				short_circuit = true;
			}
		}
		}
		else
		{
			success = execution(argv);
			if (!success)
			{
				short_circuit = true;
			}
		}
		argv++;
	}

	return (success);
}
