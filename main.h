#ifndef main_h
#define main_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#define BUFF_SIZE 1024
#define WHITESPACE " \n\t\r"

extern char **environ;

char *get_input(size_t *buffsize);
char **split_string(char *str, const char *delimiters, int *num_tokens);
void print_tokens(char **tokens, int num_tokens);
void free_tokens(char **tokens, int num_tokens);


#endif
