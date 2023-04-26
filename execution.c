#include "main.h"


void execution(char **argv, char *filename)
{
	pid_t pid;
	int status;
	char *user_command = NULL, *command = NULL;
	char **envp = environ;
/*	bool handle_logic_result;*/
	char **alias_value;
/*	char **alias_list = NULL;*/
/*	char **alias_argv;*/
	int i = 0;
/*	char logical_operator[] = NO_OPERATOR;*/
/*	char AND_OPERATOR[2];*/
  /*      char OR_OPERATOR[2];*/

/*	AND_OPERATOR[] = "&&";*/
/*	OR_OPERATOR[] = "||";*/


	user_command = argv[0];
	if (user_command[0] == '#')
	{
		return;
	}
/*	comments(user_command);*/


/*	command = get_path(user_command);*/
/*	handle_logic_result = handle_logic(argv);*/
/*	if (logical_operator == AND_OPERATOR)
	{
		if (handle_logic_result == true)
		{
			char **new_argv = get_next_command(argv);
			execution(new_argv);
			free(new_argv);
		}
	}
	else if (logical_operator == OR_OPERATOR)
	{
		if (handle_logic_result == false)
		{
			char **new_argv = get_next_command(argv);;
			execution(new_argv);
			free(new_argv);
		}
	}
	else
	{*/
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

	if ((alias_value = handle_alias(argv)))
	{
		char* alias_args[MAX_ARGS];

	        char* token = strtok(*alias_value, " ");
		while (token != NULL && i < MAX_ARGS-1)
		{
			alias_args[i++] = token;
			token = strtok(NULL, " ");
		}
		alias_args[i] = NULL;

		execution(alias_args);
		free(alias_value);
		return;
	}

	if (command == NULL)
	{
		printf("hsh: Command not found: %s%s\n", filename, user_command);
		exit(EXIT_FAILURE);
	}
/*	if (handle_logic_result == false)
	{
		return;
	}*/
	
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
