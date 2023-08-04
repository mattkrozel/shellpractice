#ifndef main_h
#define main_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024
#define WHITESPACE " \n\t\r"

extern char **environ;
int main(int ac, char **argv, char **env);
void handle(int signals);
char *get_input(size_t *buffsize);
char **split_string(char *str, const char *delimiters, int *num_tokens);
void print_tokens(char **tokens, int num_tokens);
void free_tokens(char **tokens, int num_tokens);
void execute_input(char **argv);
void print_enviro(char **env);
char *find_command(char *command);
void exit_free(char **command);
void double_free(char **command);


#endif
