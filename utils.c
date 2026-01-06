#include "shell.h"
/**
 * _strcmp - A funtion that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if strings are the same, 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * strdup - a function that duplicate a string
 * @dst: the copy of the string
 * @i: the input integer to go through the string
 * Return dst (destination copy)
 */
char *_strdup(const char *src)
{
    char *dst;
    int i, len = 0;

    if (src == NULL)
        return (NULL);

    while (src[len])
        len++;

    dst = malloc(len + 1);
    if (dst == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        dst[i] = src[i];

    return (dst);
}

/**
 * _strlen - A function that finds the length of the string
 * @s: The input string
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcpy - A function that copies a string to another string
 * @dest: The pointer to the copyed string
 * @src: The pointer to string to copy for
 * Return: A pointer to copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}

/**
 * _strcat - a function that concatenates two strings.
 * @dest: an input string
 * @src: an input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}