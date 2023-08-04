#include "main.h"

void double_free(char **command)
{
	size_t i = 0;
	if (command == NULL)
		return;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	if (command[i] == NULL)
		free(command[i]);
	free(command);
}

void exit_free(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}


