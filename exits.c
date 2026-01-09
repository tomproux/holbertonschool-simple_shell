#include "shell.h"
/**
 * shell_exit - A function that exits the shell.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
int shell_exit(char **cmd)
{
    if (!cmd || !cmd[0])
        return 0;

    if (strcmp(cmd[0], "exit") != 0)
        return 0;

    free_args(cmd);
    exit(EXIT_SUCCESS);

    return EXIT_SUCCESS;
}

/**
 * free_argv - a function that free the allocated memory
 * @i : the input integer
 * Return: nothing
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

/**
 * free_args - a function that free the allocated memory
 * @i: the input integer
 * Return: nothing
 */
void free_args(char **argv)
{
    int i = 0;

    if (!argv)
        return;

    while (argv[i])
    {
        free(argv[i++]);
    }
    free(argv);
}