#include "main.h"


void child(char **real_command, char *name, char **env, int counts)
{
	int pid = 0;
	int status = 0;
	int werror = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		exitfree(real_command);
	}
	else if (pid == 0)
	{
		execute_input(real_command, name, env, counts);
		doublefree(real_command);
	}
	else
	{
		werror = waitpid(pid, &status, 0);
		if (werror < 0)
		{
			exitfree(real_command);
		}
		doublefree(real_command);
	}
}

int changedirectory(const char *path)
{
	char *buf = NULL;
	size_t size = BUFF_SIZE;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
