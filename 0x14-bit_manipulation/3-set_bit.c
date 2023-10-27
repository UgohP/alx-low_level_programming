#include "main.h"

/**
 * set_bit - Set the value of a bit to 1 at a given index
 * @n: A pointer to the number to modify
 * @index: The index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurs
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= 64)
        return -1;

    *n |= (1UL << index);
    return 1;
}
