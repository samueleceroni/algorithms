
#include <stdbool.h>
#include <math.h>

bool is_prime (unsigned int value)
{
    unsigned long int i;
    for (i=2; i<sqrt(value); i++)
    {
        if (value%i==0)
            return false;
    }
    return true;
}