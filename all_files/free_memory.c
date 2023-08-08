#include "main.h"

void doublefree(char **real_command)
{
	size_t i = 0;
	if (real_command == NULL)
		return;
	while (real_command[i])
	{
		free(real_command[i]);
		i++;
	}
	if (real_command[i] == NULL)
		free(real_command[i]);
	free(real_command);
}

void exitfree(char **real_command)
{
	size_t i = 0;

	if (real_command == NULL)
		return;
	while (real_command[i])
	{
		free(real_command[i]);
		i++;
	}
	if (real_command[i] == NULL)
		free(real_command[i]);
	free(real_command);
	exit(EXIT_FAILURE);
}


