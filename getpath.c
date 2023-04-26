#include "main.h"

/**
 * get_path - Get full path to a command.
 *
 * @user_command: Pointer to a string with command.
 *
 * Description: Searches for command by checking,
 * each directory in the PATH environment variable.
 *
 * Return: Pointer to string containing full path - success
 * otherwise NULL
 *
 */

char *get_path(char *user_command)
{
	char *path, *path_dup, *path_dir, *dir_path;
	int command_len, dir_len;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{
		path_dup = strdup(path);

		command_len = strlen(user_command);
		path_dir = strtok(path_dup, ":");

		while (path_dir != NULL)
		{
			dir_len = strlen(path_dir);
			dir_path = malloc(command_len + dir_len + 2);

			strcpy(dir_path, path_dir);
			strcat(dir_path, "/");
			strcat(dir_path, user_command);
			strcat(dir_path, "\0");

			if (stat(dir_path, &buff) == 0)
			{
				free(path_dup);
				return (dir_path);
			}
			else
			{
				free(dir_path);
				path_dir = strtok(NULL, ":");
			}
		}
		free(path_dup);
		if (stat(user_command, &buff) == 0)
		{
			return (user_command);
		}
	}
	return (NULL);
}
