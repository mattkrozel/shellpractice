#include "main.h"

void execute_input(char **argv)
{
	char *command = NULL, *real_command = NULL;

	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
