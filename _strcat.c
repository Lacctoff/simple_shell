#include "shell.h"

/**
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: pointer of an array of chars
 */

char *str_concat(char *s1, char *s2)
{
	char *output;
	int i;
	int strlenA;
	int strlenB;

	strlenA = 0;
	strlenB = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	for (i = 0; s1[i] != '\0'; i++)
		strlenA++;

	for (i = 0; s2[i] != '\0'; i++)
		strlenB++;

	output = malloc(sizeof(char) * ((strlenA + strlenB) + 1));

	if (output == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		output[i] = s1[i];

	for (i = 0; s2[i] != '\0'; i++)
		output[strlenA + i] = s2[i];

	output[strlenA + strlenB] = '\0';
	return (output);
}
