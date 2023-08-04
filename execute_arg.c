#include "main.h"

void execute_input(char **argv)
{
	char *command = NULL, *real_command = NULL;
	pid_t pid;
	int status, error_wait = 0;

	if (argv)
	{
		command = argv[0];
		real_command = find_command(command);

		pid = fork();
		if (pid < 0)
		{
			perror("Error: ");
			free(real_command);
		}
		if (pid == 0)
		{
			execve(real_command, argv, NULL);
			free(real_command);
		}
		else
		{
			error_wait = waitpid(pid, &status, 0);
			if (error_wait < 0)
			{
				free(real_command);
			}
			free(real_command);
		}
	}
}
void print_enviro(char **env)
{
	size_t i = 0, length = 0;

	while (env[i])
	{
		length = strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
