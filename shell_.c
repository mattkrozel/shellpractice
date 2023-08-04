#include "main.h"

int main(int ac, char **argv, char **env)
{
	size_t buffsize = BUFF_SIZE;
	char *buffer, **token_array;
	size_t characters;
	char *real_command;
	int num_tokens, i;
	
	(void)ac;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}

	while (1)
	{
		buffer = get_input(&buffsize);
		signal(SIGINT, handle);
		characters = strlen(buffer);
		if (characters == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		if (characters > 0 && buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
			--characters;
		}	
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
		if (strcmp(buffer, "env") == 0)
			print_enviro(env);
/**		
 *		printf("%ld characters read \n", characters);
 *		printf("your command is %s \n", buffer);
 */
		token_array = split_string(buffer, WHITESPACE, &num_tokens);
/**		
 *		print_tokens(token_array, num_tokens);
 */

		argv = (char **)malloc(sizeof(char *) * (num_tokens + 1));

		if (!argv)
		{
			fprintf(stderr, "Memory allocation error.\n");
			exit(1);
		}
		for (i = 0; i < num_tokens; i++)
			argv[i] = strdup(token_array[i]);
		argv[num_tokens] = NULL;
		real_command = find_command(argv[0]);
		if (real_command != NULL)
		{
			execute_input(argv);
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
		}


		free_tokens(token_array, num_tokens);
		free(argv);
		fflush(stdin);
		buffer = NULL, buffsize = 0;
		
	}
	free(buffer);
	if (characters == -1)
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 2);
}
