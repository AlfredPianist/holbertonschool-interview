#include "holberton.h"

/**
 * wildcmp - compares two strings. The second one may have the * wildcard.
 * @s1: the source string.
 * @s2: the string to be compared to.
 *
 * Return: 1 if two strings are equal even with *, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (*s1 != *(s2 + 1))
			return (wildcmp(s1 + 1, s2));
		if (*(s1 + 1) == *(s2 + 1))
			return (wildcmp(s1 + 1, s2 + 1));
		if (wildcmp(s1 + 1, s2) == 1)
			return (1);
		return (wildcmp(s1, s2 + 1));
	}
	return (0);
}
