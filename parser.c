#include "shell.h"
/**
 * parse_line - a function that parse the line in an array
 * Cut the line and take the argument 
 * Return the argument
 */
char **parse_line(char *line)
{
    char **argv = NULL;
    char *token = NULL;
    int i = 0;

    token = strtok(line, " \n");
    if (token == NULL)
        return (NULL);

    while (token != NULL)
    {
        argv = realloc(argv, sizeof(char *) * (i + 2));
        if (!argv)
            return (NULL);

        argv[i] = strdup(token);
        if (!argv[i])
            return (NULL);

        i++;
        token = strtok(NULL, " \n");
    }

    argv[i] = NULL;
    return (argv);
}

/**
 * free_argv - a function that free the allocated memory
 * @i : the input integer
 * Return nothing
 */
void free_argv(char **argv)
{
    int i = 0;

    if (!argv)
        return;

    while (argv[i])
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}
