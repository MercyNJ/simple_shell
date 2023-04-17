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
	char* shell_prompt;
	char *lineptr = NULL, *lineptr_dup = NULL;
	size_t n = 0;
	ssize_t num_chars;
	const char *delim = " \n";
	int token_count = 0;
	char *token;
	int i;


	(void)argc;

	shell_prompt = "(&) ";

	while (1)
    	{
        printf("%s", shell_prompt);
        num_chars = getline(&lineptr, &n, stdin); 
        if (num_chars == -1)
        {
            printf("Exiting shell ...\n");
            return (-1);
        }

        lineptr_dup = malloc(sizeof(char) * num_chars);
        if (lineptr_dup == NULL)
        {
            perror("hsh: memory allocation error");
            return (-1);
        
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
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

	execution(argv);

	}

	free(lineptr);
	free(lineptr_dup);
	free(argv);
	return (0);
}
