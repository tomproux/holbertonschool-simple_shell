#include "shell.h"
/**
 * execute_command - a function that execute an external command
 * @pid_t: is the parent identification
 * @cmd_path: is the path command  
 * Return nothing
 */
int execute_command(char **argv)
{
    pid_t pid;
    int status;
    char *cmd_path;

    if (!argv || !argv[0])
        return 0;

    if (handle_builtins(argv))
        return 0;

    cmd_path = find_command_path(argv[0]);
    if (!cmd_path)
    {
        fprintf(stderr, "%s: command not found\n", argv[0]);
        return 127;
    }

    pid = fork();
    if (pid == 0)
    {
        execve(cmd_path, argv, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, &status, 0);
    free(cmd_path);

    if (WIFEXITED(status))
        return WEXITSTATUS(status);

    return 1;
}