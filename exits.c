#include "shell.h"
/**
* main- a function that allow the exit function
* return: Always 0 (SUCCESS)
*/
int sortie(void)
{
	char *cmd = "";

	if (strcmp(cmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}