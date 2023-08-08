#include "main.h"

int main(int ac, char **argv, char **env)
{
	size_t buffsize = 0;
	char *buffer = NULL, **real_command;
	ssize_t characters;
	int counts;
	
	(void)ac;

	while (1)
	{
		counts++;
		if (isatty(STDIN_FILENO))
		{
			printf("$: ");
			fflush(stdout);
		}
		signal(SIGINT, flag);
		characters = getline(&buffer, &buffsize, stdin);
		if (characters == EOF)
		{
			if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
				fflush(stdout);
			}
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[strlen(buffer) - 1] = '\0';
			real_command = tokenator(buffer, "\0");
			free(buffer);
			if (strcmp(real_command[0], "exit") != 0)
				exitshell(real_command);

			else if (strcmp(real_command[0], "cd") != 0)
					changedirectory(real_command[1]);
			else
				child(real_command, argv[0], env, counts);
		}
		fflush(stdin);
		buffer = NULL, buffsize = 0;
	}
	if (characters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/**
 *		if (strcmp(buffer, "env") == 0)
 *			print_enviro(env);
 */

void flag(int signals)
{
	(void)signals;
	printf("\n$: ");
	fflush(stdout);
}


void exitshell(char **real_command)
{
	int x = 0;
	if (real_command[1] == NULL)
	{
		doublefree(real_command);
		exit(EXIT_SUCCESS);
	}
	x = atoi(real_command[1]);
	doublefree(real_command);
	exit(x);
}
