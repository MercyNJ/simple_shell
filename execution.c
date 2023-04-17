#include "main.h"

extern char **environ;

void execution(char **argv)
{
	char *user_command;

	user_command = argv[0];

	if (execve(user_command, argv, NULL) == -1)
	{
		perror("hsh: Execution error");
	}
}
