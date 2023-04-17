#include "main.h"

extern char **environ;

void execution(char **argv)
{
	char *user_command = NULL, *command = NULL;

	user_command = argv[0];
	
	command = get_path(user_command);


	if (execve(command, argv, NULL) == -1)
	{
		perror("hsh: Execution error");
	}
}
