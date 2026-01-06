#include "shell.h"
/**
* sortie - a function that allow the exit function
* return: Always 0 (SUCCESS)
*/
int sortie(void)
{
	char *cmd = "";

	if (strcmp(cmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return(0);
}

/**
 * _atoi - a function that convert a string to an integer
 * @i: the input to go through the string
 * @sign: the positive or negative sign
 * Return an integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	if (s == NULL)
		return (0);

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
