#include "main.h"

/**
 * _strcmp - A function used to compare two strings
 * @str1: String 1 to be imputed
 * @str2: String 2 to be imputed
 * Return: always success
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
