#include "shell.h"
/**
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @cicles: Number of cicles.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void msgerror(char *name, int cicles, char **command)
{
	char c;

	c = cicles + '0';
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &c, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command[0], _strlen(command[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}
