#include "main.h"

/**
 * my_getline - Takes user input from stdin
 * @lineptr: pointer to the buffer
 * @n: buffer
 * @stream: stdin
 *
 * Return: Nothing
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_chars = 0;
	ssize_t buffer_size = 0;
	int c;

	if (*lineptr == NULL)
	{
		*n = 1024;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
		if (num_chars >= buffer_size)
		{
			buffer_size += 256;
			*lineptr = realloc(*lineptr, buffer_size);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		c = fgetc(stream);
		if (c == EOF)
		{
			break;
		}
		(*lineptr)[num_chars] = c;
		num_chars++;
		if (c == '\n')
		{
			break;
		}
	}
	if (num_chars == 0)
	{
		return (-1);
	}
	(*lineptr)[num_chars] = '\0';
	return (num_chars);
}
