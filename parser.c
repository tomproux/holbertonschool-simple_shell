#include "shell.h"
/**
 * parse_line - a function that parse the line in an array
 * Cut the line and take the argument 
 * @temp: pointer to secure argv
 * @token: the input command
 * @i: the input integer to go through the array
 * Return the argument
 */
char **parse_line(char *line)
{
    char **argv = NULL;
    char **tmp;
    char *token;
    int i = 0;

    if (!line)
        return (NULL);

    token = strtok(line, " \n");
    if (!token)
        return (NULL);

    while (token)
    {
        tmp = realloc(argv, sizeof(char *) * (i + 2));
        if (!tmp)
        {
            free_args(argv);
            return (NULL);
        }
        argv = tmp;

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
