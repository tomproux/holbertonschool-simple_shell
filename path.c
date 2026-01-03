#include "shell.h"
/**
 * find_command_path - a function that search the path
 * 
 * 
 */
char *find_command_path(char *command)
{
    char *path, *path_copy, *dir;
    char *full_path;

    if (access(command, X_OK) == 0)
        return (strdup(command));

    path = getenv("PATH");
    if (!path)
        return (NULL);

    path_copy = strdup(path);
    dir = strtok(path_copy, ":");

    while (dir)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_path)
            break;

        sprintf(full_path, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}