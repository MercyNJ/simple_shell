#include "main.h"

char *my_strtok(char *str, const char *delim)
{
	static char *last_token = NULL;
	char *token;

	if (str == NULL && last_token == NULL)
	{
		return (NULL);
	}

	if (str != NULL)
	{
		last_token = str;
	}

	token = last_token;

	while (*token != '\0' && strchr(delim, *token) != NULL)
	{
		last_token++;
	}

	if (*last_token != '\0')
	{
		*last_token = '\0';
		last_token++;
	}

	return token;
}
