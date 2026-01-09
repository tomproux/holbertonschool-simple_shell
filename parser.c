#include "shell.h"
/**
 * parse_line - a function that parse the line in an array
 * @line: Cut the line and take the argument
 * Return: the argument
 */
char **parse_line(char *line)
{
	char **argv;
	char *token;
	int count = 0;
	int i = 0;
	char *copy;

	if (!line)
		return (NULL);
	copy = strdup(line);
	if (!copy)
		return (NULL);
	token = strtok(copy, " \n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	free(copy);
	if (count == 0)
		return (NULL);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	token = strtok(line, " \n");
	while (token)
	{
	argv[i] = strdup(token);
	if (!argv[i])
	{
		free_args(argv);
		return (NULL);
	}
	i++;
	token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	return (argv);
}
