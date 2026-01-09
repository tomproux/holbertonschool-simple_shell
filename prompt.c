#include "shell.h"

/**
 * read_input - a function that allow us to put argument in input
 * Return: the line
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * handle_builtins - a function that handle the builtins
 * @argv : argument table
 * Return: Always 0 (SUCCESS)
 */
int handle_builtins(char **argv)
{
	int i = 0;

	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
		exit(0);

	if (strcmp(argv[0], "env") == 0)
	{
		while (environ[i])
		{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
		}
		return (1);
	}
	return (0);
}

/**
 * _EOF - A function that checks if the buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
