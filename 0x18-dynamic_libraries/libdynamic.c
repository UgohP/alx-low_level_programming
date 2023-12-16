#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _islower - checks if a character is a lowercase letter
 * @c: character to check
 * Return: 1 if lowercase, 0 otherwise
 */
int _islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

/**
 * _isalpha - checks if a character is an alphabetic character
 * @c: character to check
 * Return: 1 if alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
    return _islower(c) || _isupper(c);
}

/**
 * _abs - computes the absolute value of an integer
 * @n: integer to compute absolute value for
 * Return: absolute value of n
 */
int _abs(int n)
{
    return (n >= 0) ? n : -n;
}

/**
 * _isupper - checks if a character is an uppercase letter
 * @c: character to check
 * Return: 1 if uppercase, 0 otherwise
 */
int _isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

/**
 * _isdigit - checks if a character is a digit (0 through 9)
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
