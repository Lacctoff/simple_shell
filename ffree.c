#include "shell.h"

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
