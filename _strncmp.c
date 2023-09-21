#include "shell.h"

/**
 * _strncmp - compares two strings up to a specified number of characters
 * @s1: first string.
 * @s2: second string.
 * @n: maximum number of characters to compare.
 * Return:
 *   0 if the first n characters of s1 and s2 are equal,
 *   a negative value if s1 is less than s2,
 *   a positive value if s1 is greater than s2.
 */


int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	int operation;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		operation = s1[i] - s2[i];
		if (operation != 0)
		{
			return (operation);
		}
	}

	if (i == n)
	{
		/*Both strings are equal up to the specified number of characters.*/
		return (0);
	}

	return (s1[i] - s2[i]);
}
