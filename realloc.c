#include "shell.h"

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
