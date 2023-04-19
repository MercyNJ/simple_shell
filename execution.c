#include "main.h"

extern char **environ;

void execution(char **argv)
{
	pid_t pid;
	int status;
	char *user_command = NULL, *command = NULL;

	user_command = argv[0];
	command = get_path(user_command);

	if (strcmp(user_command, "exit") == 0)
	{
		handle_exit(argv);
		return;
	}

	if (command == NULL)
	{
		printf("hsh: Command not found: %s\n", user_command);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("hsh: Fork failure");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("hsh: Execution error");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("hsh: waitpid failure");
				exit(EXIT_FAILURE);
			}
		}
	}
}
