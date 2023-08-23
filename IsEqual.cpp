#include <math.h>
#include <assert.h>

const double MEASURE_ERROR = 0.000001;

enum boolean
    {
    False = 0,
    True = 1
    };

boolean IsEqual(double a, double b)
    {
    assert(isfinite(a));
    assert(isfinite(b));

    if (abs(a - b) <= MEASURE_ERROR)
        {
        return True;
        }
    return False;
    }
