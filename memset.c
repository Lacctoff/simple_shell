#include "shell.h"

/**
 * _memset - Populates a memory region with constant byte
 * @s: pointer to memory area
 * @b: The byte to use for filling *s
 * @n: The number of bytes to fill
 * Return: (s) as a pointer to the updated memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
