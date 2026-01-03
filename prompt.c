#include "shell.h"
/**
 * display_prompt - a function that display a prompt
 * Return nothing
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_input - a function that allow us to put argument in input
 * @*line : a pointer on the line
 * @size_t : the lenght of the string
 * Return the line
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
 * parse_line - a function that parse the line in an array
 * Cut the line and take the first argument 
 * Return the number of argument
 */
char **parse_line(char *line)
{
    char **argv = malloc(sizeof(char *) * 2);
    char *token;

    if (!argv)
        return (NULL);

    token = strtok(line, " \n");
    if (token == NULL)
    {
        free(argv);
        return (NULL);
    }

    argv[0] = strdup(token);
    argv[1] = NULL;

    return (argv);
}

/**
 * handle_builtins - a function that handle the builtins
 * 
 */
int handle_builtins(char **argv)
{
    if (strcmp(argv[0], "exit") == 0)
        exit(0);
    return (0);
}

/**
 * execute_command - a function that execute an external command
 * @pid_t : is the parent identification  
 * Return nothing
 */
void execute_command(char **argv)
{
    pid_t pid;
    char *cmd_path;

    pid = fork();

    if (pid == 0)
    {
        cmd_path = find_command_path(argv[0]);
        if (!cmd_path)
        {
            write(STDERR_FILENO, "command not found\n", 18);
            exit(127);
        }

        execve(cmd_path, argv, NULL);
        perror("hsh");
        free(cmd_path);
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}