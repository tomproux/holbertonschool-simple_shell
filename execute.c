#include "shell.h"
/**
 * execute_cmd - execute a command
 * @argv: an array (argv[0] = command, argv[1..] = args)
 *
 * Return: 0 on sucess, -1 if error
 */
int execute_cmd(char **argv)
{
    pid_t pid;
    int status;

    if (argv == NULL || argv[0] == NULL)
        return (-1);

    if (handle_builtins(argv))
        return (0);

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (-1);
    }

    if (pid == 0)
    {
        char *path = find_command_path(argv[0]);
        if (!path)
        {
            fprintf(stderr, "%s: command not found\n", argv[0]);
            exit(127);
        }

        execve(path, argv, environ);
        perror("execve");
        exit(1);
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return (-1);
        }

        if (WIFEXITED(status))
            return WEXITSTATUS(status);
    }

    return (0);
}