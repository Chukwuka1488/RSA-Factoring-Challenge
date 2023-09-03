#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

/**
 * factorize - factorize a number into a product of two smaller numbers
 * @n: the number to factorize
 *
 * Return: 0 if a factorization was found, 1 if n is prime
 */
int factorize(uint64_t n)
{
    uint64_t i;

    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, n / i, i);
            return (0);
        }
    }

    return (1);
}

/**
 * main - entry point
 * @argc: the number of command line arguments
 * @argv: the array of command line arguments
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(int argc, char *argv[])
{
    FILE *f;
    uint64_t n;

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error: could not open file %s\n", argv[1]);
        return (1);
    }

    while (fscanf(f, "%" SCNu64, &n) == 1)
    {
        if (factorize(n))
            printf("%" PRIu64 " is a prime number\n", n);
    }

    fclose(f);
    return (0);
}
