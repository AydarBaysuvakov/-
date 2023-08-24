#ifndef header
#define header
#include <math.h>

enum IOError
    {
    OK    = 0,
    ERROR = -1
    };

enum RootsCount
    {
    INF_ROOTS = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
    };

struct Coefs
    {
    double a;
    double b;
    double c;
    };

struct Roots
    {
    double x1;
    double x2;
    };

#endif
