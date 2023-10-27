#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Convert a binary number to an unsigned int
 * @b: A pointer to a string of 0 and 1 characters
 *
 * Return: The converted number, or 0 if an error occurs
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;

    if (b == NULL)
        return 0;

    while (*b)
    {
        if (*b != '0' && *b != '1')
            return 0;

        result = (result << 1) | (*b - '0');
        b++;
    }

    return result;
}
