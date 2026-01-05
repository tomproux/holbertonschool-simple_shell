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
 * atoi - a function that convert a string to an integer
 * @i : input integer
 * @sign : sign of the integer
 * @result : result integer
 * Return: integer value
 */
int atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;

	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
		sign = -1;
		i++;
	}
	while(str[i] >= 0 && str[i] <= 9)
	{
	result = result * 10 + (str[i] - '0');
	i++;
	}
	return(result * sign);
}