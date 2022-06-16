#include "palindrome.h"

/**
 * is_palindrome - Checks if a number is palindromic.
 * @n: The number to be checked.
 *
 * Return: 1 if number is palindromic. 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long temp, reverse;

	temp = n;
	reverse = 0;
	while (temp != 0)
	{
		reverse = (temp % 10) + (reverse * 10);
		temp /= 10;
	}
	return (reverse == n);
}
