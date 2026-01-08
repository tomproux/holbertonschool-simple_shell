#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

int main(void);
void free_argv(char **argv);
void free_args(char **argv);
void display_prompt(void);
char *read_input(void);
char **parse_line(char *line);
void print_env(char **env);
int handle_builtins(char **argv);
void execute_command(char **argv);
char *find_command_path(char *command);
char *_getPATH(void);
int sortie(void);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char *strdup(const char *src);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void msgerror(char *name, int cicles, char **command);
extern char **environ;

#endif
