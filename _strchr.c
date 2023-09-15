#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: string.
 * @c: charcter to be inputed.
 * Return: return pointer to first occurence of charcater c.
 */

char *_strchr(char *s, char c)
{
	unsigned int j;

	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] == c)
			return (s + j);
	}
	if (s[j] == c)
		return (s + j);
	return (NULL);
}
