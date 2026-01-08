#include "shell.h"
/**
* sortie - a function that allow the exit function
* return: Always 0 (SUCCESS)
*/
int sortie(void)
{
	char *cmd = "";

	if (strcmp(cmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return(0);
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

/**
 * free_argv - a function that free the allocated memory
 * @i : the input integer
 * Return nothing
 */
void free_args(char **argv)
{
    int i = 0;
    if (!argv)
        return;
    while (argv[i])
        free(argv[i++]);
    free(argv);
}
