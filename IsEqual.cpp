#include <math.h>
#include "assert.h"

const double MEASURE_ERROR = 0.000001;

enum boolean
    {
    False = 0,
    True = 1
    };

boolean IsEqual(double a, double b)
    {
    myAssert(isfinite(a));
    myAssert(isfinite(b));

    if (abs(a - b) <= MEASURE_ERROR)
        {
        return True;
        }
    return False;
    }