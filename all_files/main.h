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
void flag(int signals);
void exitshell(char **real_command);
char **tokenator(char *str, const char *delimiters);
void execute_input(char **real_command, char *name, char **env, int counts);
char **get_path(char **env);
void errormessage(char *name, int counts, char **real_command);
void print_enviro(char **env);
void child(char **real_command, char *name, char **env, int counts);
int changedirectory(const char *path);
void exitfree(char **real_command);
void doublefree(char **real_command);


#endif
