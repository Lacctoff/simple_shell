#include "main.h"


/**
 * is_whitespace - function checks if a character is a whitespace
 * @ch: takes in the charcater to check for.
 *
 * Return:returns the detected whitespace character.
 */
int is_whitespace(char ch)
{
        return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f');
}
