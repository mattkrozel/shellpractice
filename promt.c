#include "main.h"

char *get_input(size_t *buffsize)
{
	ssize_t characters;
	char *buffer = NULL;
	if (isatty(STDIN_FILENO))
	{	
		write(STDOUT_FILENO, "$ ", 2);
	}
	characters = getline(&buffer, buffsize, stdin);

	if (characters == EOF)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	if (characters > 0 && buffer[characters - 1] == '\n')
	{
		buffer[characters - 1] = '\0';
		--characters;
	}

	return (buffer);
}
