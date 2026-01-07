#include "shell.h"
/**
 * display_prompt - a function that display and execute a prompt
 * Return nothing
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;
    char *argv[2];

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&line, &len, stdin);

        if (nread == -1)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        if (nread > 0 && line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] == '\0')
            continue;

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }

        if (pid == 0)
        {
            argv[0] = line;
            argv[1] = NULL;

            execve(line, argv, NULL);

            perror("./simple_shell");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
    }

    free(line);
    return 0;
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
 * handle_builtins - a function that handle the builtins
 * @i : an input integer
 * Return nothing
 */
int handle_builtins(char **argv)
{
    int i = 0;
    extern char **environ;

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
 * execute_command - a function that execute an external command
 * @pid_t: is the parent identification
 * @cmd_path: is the path command  
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
