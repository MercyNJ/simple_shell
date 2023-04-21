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
	int count;

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
                        handle_env();
                        continue;
                }

                lineptr_dup = malloc(sizeof(char) * num_chars);
                if (lineptr_dup == NULL)
                {
                        perror("hsh: memory allocation error");
                        exit(EXIT_FAILURE);
                }
		strcpy(lineptr_dup, lineptr);
                token = my_strtok(lineptr, delim);

                while (token != NULL)
                {
                        token_count++;
                        token = my_strtok(NULL, delim);
                }
                token_count++;
                argv = malloc(sizeof(char *) * token_count);
                token = my_strtok(lineptr_dup, delim);

                for (i = 0; token != NULL; i++)
                {
                        argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
                        strcpy(argv[i], token);
                        token = my_strtok(NULL, delim);
			 }
                argv[i] = NULL;

		for (count = 0; count < argc; count++)
		{
			printf("Argv[%d] = %s\n", count, argv[count]);
		}

               /* execution(argv);*/

                free(lineptr);
                free(lineptr_dup);
		
        }
	free(argv);


        return (0);
}     
