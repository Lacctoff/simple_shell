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

/**
 * ffree -Releases memory allocated for collection of strings
 * @pp: A string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Adjusts the size of a memory block
 * @ptr:  Pointer to a previously allocated block of memory
 * @old_size: Size of the old block in bytes.
 * @new_size: Size of the new block in bytes.
 *
 * Return: a pointer to the updated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
