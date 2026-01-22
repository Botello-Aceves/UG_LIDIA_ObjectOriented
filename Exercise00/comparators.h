#ifndef COMPARATORS_H
#define COMPARATORS_H

#include "math.h"

int ascending(int a, int b)
{
    return a < b;
}

int descending(int a, int b)
{
    return a > b;
}

int absolute(int a, int b)
{
    return abs(a) < abs(b);
}

int even_first(int a, int b)
{
    if ((a % 2 == 0) && (b % 2 != 0)) return 1;
    if ((a % 2 != 0) && (b % 2 == 0)) return 0;
    return a < b;
}

#endif
