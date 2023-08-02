#include "main.h"

int main(void)
{
	size_t buffsize = BUFF_SIZE;
	char *buffer, *buffer_copy, **token_array;
	size_t characters;
	int num_tokens;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}

	while (1)
	{
		buffer = get_input(&buffsize);
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
		buffer_copy = malloc(sizeof(char) * characters);
		if (buffer_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(buffer_copy, buffer);
		printf("%ld characters read \n", characters);
		printf("your command is %s \n", buffer);
		token_array = split_string(buffer, WHITESPACE, &num_tokens);
		print_tokens(token_array, num_tokens);
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);

		free_tokens(token_array, num_tokens);

		
	}
	return (0);
}
