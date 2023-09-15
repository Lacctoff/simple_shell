#include "main.h"

/**
 * custom_getenv - custom implementation of the getenv function
 * @name: the name of the environment variable to retrieve
 * Return: a pointer to the value associated with the name,
 * or NULL if not found
 */
char *custom_getenv(char *name)
{
	int i;
	size_t name_len = _strlen(name);

	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}

	return (NULL);
}

