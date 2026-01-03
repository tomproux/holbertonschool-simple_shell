#include "shell.h"
#include <dirent.h>
/**
 * a function to create the ls function
 * 
 * Return nothing
 */
int ls_function(void)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir");
        return (1);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return (0);
}

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
