#include <stdio.h>
#include <stdlib.h>

/**
 * add - Adds two integers
 * @a: First integer
 * @b: Second integer
 * Return: Sum of a and b
 */
int add(int a, int b)
{
    return a + b;
}

/**
 * sub - Subtracts two integers
 * @a: First integer
 * @b: Second integer
 * Return: Difference of a and b
 */
int sub(int a, int b)
{
    return a - b;
}

/**
 * mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 * Return: Product of a and b
 */
int mul(int a, int b)
{
    return a * b;
}

/**
 * div - Divides two integers
 * @a: First integer (dividend)
 * @b: Second integer (divisor)
 * Return: Result of the division of a by b
 */
int div_op(int a, int b)
{
    if (b != 0)
        return a / b;
    else
    {
        fprintf(stderr, "Error: Cannot divide by zero\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * mod - Computes the remainder of the division of two integers
 * @a: First integer (dividend)
 * @b: Second integer (divisor)
 * Return: Remainder of the division of a by b
 */
int mod(int a, int b)
{
    if (b != 0)
        return a % b;
    else
    {
        fprintf(stderr, "Error: Cannot mod by zero\n");
        exit(EXIT_FAILURE);
    }
}
