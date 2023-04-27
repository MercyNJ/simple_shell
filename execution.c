#include "main.h"


void execution(char **argv, char *filename)
{
	pid_t pid;
	int status;
	char *user_command = NULL, *command = NULL;
	char **envp = environ;
	user_command = argv[0];
	if (user_command[0] == '#')
	{
		return;
	}
		command = get_path(user_command);


	if (strcmp(user_command, "exit") == 0)
	{
		handle_exit(argv);
		return ;
	}
	else if (strcmp(user_command, "setenv") == 0)
                {
                        set_env(envp, argv[1], argv[2], 1);
                        return ;
                }

	else if (strcmp(user_command, "cd") == 0)
	{
		my_cd(argv[1]);
		return ;
	}

	else if (strcmp(user_command, "unsetenv") == 0)
	{
		unset_env(envp, argv[1]);
		return ;
	}


	if (command == NULL)
	{
		printf("hsh: Command not found: %s%s\n", filename, user_command);
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
		if (execve(command, argv, envp) == -1)
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
	return; 
}
