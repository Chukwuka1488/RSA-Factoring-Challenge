#include <stdio.h>
#include <math.h>

/**
 * main - factorizes numbers from a file
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 if successful, 1 otherwise
 */
int main(int argc, char *argv[])
{
    FILE *f;
	double n;
    int found, i;

    if (argc != 2)
    {
        printf("Usage: factors <file>\n");
        return (1);
    }

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error: could not open file %s\n", argv[1]);
        return (1);
    }

    while (fscanf(f, "%lf", &n) == 1)
    {
        found = 0;
        for (i = 2; i <= sqrt(n); i++)
        {
            if ((int)n % i == 0)
            {
                printf("%d=%d*%d\n", (int)n, (int)(n/i), i);
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("%d is a prime number\n", (int)n);
        }
    }

    fclose(f);
    return (0);
}
