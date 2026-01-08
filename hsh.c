#include "shell.h"
/**
 * main - a function which is the main loop of the shell
 * @line: is the command line
 * @argv: is the array of argument for the command
 * @interactive: is the interactive mode of the shell
 * Return: always 0.
 */
int main(void)
{
    char *line = NULL;
    char **argv = NULL;
    int interactive = isatty(STDIN_FILENO);

    while (1)
    {
        if (interactive)
            display_prompt();

        line = read_input();
        if (line == NULL)
            break;

        argv = parse_line(line);
        if (argv == NULL || argv[0] == NULL)
        {
            free(line);
            free_argv(argv);
            continue;
        }

        if (handle_builtins(argv))
        {
            free(line);
            free_argv(argv);
            continue;
        }

        execute_command(argv);

        free(line);
        free_argv(argv);
    }
    return (0);
}

/**
 * prompt - A function that display the prompt
 * Return: Nothing.
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}