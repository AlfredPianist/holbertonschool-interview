#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: the source string.
 * @pattern: the pattern to be matched.
 *
 * Return: 1 if pattern matches, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	int dot = 0, star = 0;

	if (!(str && pattern))
		return (0);

	dot = *str && ((*pattern == '.') || (*str == *pattern));
	star = *(pattern + 1) == '*';

	if (!(*str || star))
		return (*pattern ? 0 : 1);

	if (star)
	{
		if (dot)
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	else if (dot)
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
