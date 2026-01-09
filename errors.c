#include "shell.h"
/**
 * msgerror - A function that prints command not found.
 * @hsh: the name of the shell
 * @line: the command counter
 * @cmd: The pointer to tokenized command
 * @msg: the error messageexit
 * Return: Nothing.
 */
void print_error(char *hsh, int line, char *cmd, char *msg)
{
    char num[20];
    int i = 0, n = line;

    write(STDERR_FILENO, hsh, _strlen(hsh));
    write(STDERR_FILENO, ": ", 2);

    if (line >= 0)
    {
        if (n == 0)
            num[i++] = '0';

        while (n)
        {
            num[i++] = (n % 10) + '0';
            n /= 10;
        }

        while (--i >= 0)
            write(STDERR_FILENO, &num[i], 1);

        write(STDERR_FILENO, ": ", 2);
    }

    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, msg, _strlen(msg));
    write(STDERR_FILENO, "\n", 1);
}