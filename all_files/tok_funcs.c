#include "main.h"

char **tokenator(char *buffer, const char *delimiters)
{	
	char *token = NULL, **real_command = NULL;
	size_t buffsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	buffsize = strlen(buffer);
	real_command = malloc((buffsize + 1) * sizeof(char *));
	if (real_command == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		doublefree(real_command);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delimiters);
	while (token != NULL)
	{
		real_command[i] = malloc(strlen(token) + 1);
		if (real_command[i] == NULL)
		{
			perror("Unable to allocate buffer");
			doublefree(real_command);
			return (NULL);
		}
		strcpy(real_command[i], token);
		token = strtok(NULL, delimiters);
		i++;
	}
	real_command[i] = NULL;
	return (real_command);
}
