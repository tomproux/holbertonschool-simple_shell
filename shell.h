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
void display_prompt(void);
void msgerror(char *name, int cicles, char **command);
void _EOF(char *buffer);
char **parse_line(char *line);
void free_argv(char **argv);
void free_args(char **argv);
char *read_input(void);
void print_env(char **env);
char *_getenv(const char *name);
int handle_builtins(char **argv);
char *_getPATH(void);
int execute_command(char **argv);
char *find_command_path(char *command);
int shell_exit(char **cmd);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
extern char **environ;

#endif
