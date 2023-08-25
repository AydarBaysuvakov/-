#include <math.h>
#include "my_assert.h"
#include "is_equal.h"

int IsEqual(double a, double b)
    {
    myAssert(isfinite(a));
    myAssert(isfinite(b));

    return abs(a - b) <= MEASURE_ERROR;
    }
