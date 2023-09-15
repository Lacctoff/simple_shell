#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string to be copied to the new memory.
 * Return: pointer of an array of chars.
 */
char *_strdup(char *str)
{
	char *dest;
	int count;
	int i;

	count = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	dest = malloc(sizeof(char) * (count + 1));

	if (dest == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}
	return (dest);
}
