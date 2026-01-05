#include "shell.h"

/*
* fork- permet de créer un processus fils
* return: Always 0 (SUCCESS)
*/
int fork(void)
{
    int pidChild;

    if (pidChild != 0)
    {
        pidChild = getpid();
    }

    return (pidChild); 
}

/*
* execve-
*/
void execve(char **path, char **argv, char **env)
{

}

/*
* wait- permet d'attentre un autre processus
* return: pid and status of the child
*/
int **wait(void)
{
    int **infoChild;
    int i;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            infoChild[i] = getpid();
        }
        else if(i == 1)
        {
            infoChild[i] = getstatus();
        }
    }

    return infoChild;
}