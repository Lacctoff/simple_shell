#include "shell.h"

/**
 * starts_with -  Verifies if the 'needle' begins with the 'haystack'
 * @haystack: The string being searched.
 * @needle: The substring to locate at the beginning.
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
