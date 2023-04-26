#include "main.h"

/**
 * execute_file-Opens files and executes commands within it
 * @argc: No of args passed
 * @argv: The argument passed
 *
 * Return: always (0) success
 */
int execute_file(int argc, char **argv)
{
	char user_command[MAX_COMMAND_LEN];
	char filename[MAX_FILENAME_LEN];
	FILE *fptr;

	if (argc != 2)
	{
		printf("hsh: simple_shell [filename]");
		return (1);
	}

	strncpy(filename, argv[1], MAX_FILENAME_LEN);

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf("hsh: Could not open file %s\n", filename);
		return (1);
	}

	while (fgets(user_command, MAX_COMMAND_LEN, fptr) != NULL)
	{
		system(user_command);
	}

	fclose(fptr);

	return (0);
}
