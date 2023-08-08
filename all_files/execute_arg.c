#include "main.h"

void execute_input(char **real_command, char *name, char **env, int counts)
{
	char **paths = NULL, *final_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (strcmp(real_command[0], "env") != 0)
		print_enviro(env);
	if (stat(real_command[0], &st) == 0)
	{
		if  (execve(real_command[0], real_command, env) < 0)
		{
			perror(name);
			exitfree(real_command);
		}
	}
	else
	{
		paths = get_path(env);
		while (paths[i])
		{
			final_path = strcat(paths[i], real_command[0]);
			i++;
			if (stat(final_path, &st) == 0)
			{
				if (execve(final_path, real_command, env) < 0)
				{
					perror(name);
					doublefree(paths);
					exitfree(real_command);
				}
				return;
			}
		}
		errormessage(name, counts, real_command);
		doublefree(paths);
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



char **get_path(char **env)
{
	char *val = NULL, **paths = NULL;
	unsigned int i = 0;

	val = strtok(env[i], "=");
	while (env[i])
	{
		if (strcmp(val, "PATH"))
		{
			val = strtok(NULL, "\n");
			paths = tokenator(val, ":");
			return (paths);
		}
		i++;
		val = strtok(env[i], "=");
	}
	return (NULL);
}

void errormessage(char *name, int counts, char **real_command)
{
	char c;

	c = counts + '0';
	write(STDOUT_FILENO, name, strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, real_command[0], strlen(real_command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
