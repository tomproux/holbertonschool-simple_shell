#include "shell.h"
/**
 * find_command_path - a function that search the complete path of a function
 * @path: value of the environnement variable
 * @path_copy: copy of path
 * @dir: the different directory
 * 
 */
char *find_command_path(char *command)
{
    char *path_env, *path_copy, *dir;
    char *full_path;

    if (access(command, X_OK) == 0)
        return strdup(command);

    path_env = _getenv("PATH");
    if (!path_env)
        return NULL;

    path_copy = strdup(path_env);
    if (!path_copy)
        return NULL;

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
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

/**
 * _getenv - a function that look for a environnement variable
 */
char *_getenv(const char *name)
{
    int i;
    size_t len;

    if (!name || !environ)
        return NULL;

    len = strlen(name);

    for (i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], name, len) == 0
            && environ[i][len] == '=')
        {
            return (environ[i] + len + 1);
        }
    }
    return NULL;
}

/**
 * _getPATH - a function that give the path environnement variable
 */
char *_getPATH(void)
{
    return _getenv("PATH");
}