#include "main.h"

/**
 * main - The entry point of our program.
 * @argc: The argument count.
 * @argv: The arguments vector.
 *
 * Return: Always 0(Success)
 */

int main(int argc, char **argv)
{
        char *shell_prompt;
        char *lineptr = NULL, *lineptr_dup = NULL;
        size_t n = 0;
        ssize_t num_chars;
        const char *delim = " \n";
        int token_count = 0;
        char *token;
        int i;
	char **envp = environ;
	char *var;
	char *filename = NULL;
	/*int count;*/

        (void)argc;

        shell_prompt = "(&) ";


        while (1)
        {
                printf("%s", shell_prompt);
		num_chars = my_getline(&lineptr, &n, stdin);
                if (num_chars == -1)
                {
                        printf("Exiting shell ...\n");
                        return (-1);
                }

                else if (strcmp(lineptr, "env\n") == 0)
                {
                        handle_env(envp);
                        continue;
                }

		else if (strncmp(lineptr, "cd", 2) == 0)
		{
			my_cd(lineptr + 2);
			continue;
		}

		else if (strncmp(lineptr, "unsetenv", 8) == 0)
		{
			var = strtok(lineptr + 8, delim);
			if (unset_env(envp, var) != 0)
			{
				fprintf(stderr, "Error unsetting variable %s\n", var);
			}
			continue;
		}

                lineptr_dup = malloc(sizeof(char) * num_chars);
                if (lineptr_dup == NULL)
                {
                        perror("hsh: memory allocation error");
                        exit(EXIT_FAILURE);
                }
		strcpy(lineptr_dup, lineptr);
                token = strtok(lineptr, delim);

                while (token != NULL)
                {
                        token_count++;
                        token = strtok(NULL, delim);
                }
                token_count++;
                argv = malloc(sizeof(char *) * token_count);
                token = strtok(lineptr_dup, delim);

                for (i = 0; token != NULL; i++)
                {
                        argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
                        strcpy(argv[i], token);
                        token = strtok(NULL, delim);
			 }
            /*    argv[i] = NULL;*/
		  argv[token_count - 1] = NULL;

		/*for (count = 0; count < argc; count++)
		{
			printf("Argv[%d] = %s\n", count, argv[count]);
		}*/

                execution(argv, filename);

               /*free(lineptr);*/
                free(lineptr_dup);
		free(argv);
		
        }


        return (0);
}     
