#include "my_assert.h"
#include "solving_functions.h"
#include "is_equal.h"


RootsCount SolveSquare(Coeffs coeffs, Roots *roots_p)
    {
    /* Проверка ошибок */
    myAssert (isfinite(coeffs.a));
    myAssert (isfinite(coeffs.b));
    myAssert (isfinite(coeffs.c));
    myAssert (roots_p != NULL);

    if (IsEqual(coeffs.a, 0))
        {
        return SolveLinear(coeffs.b, coeffs.c, &roots_p->x1);
        }
    else
        {
        double d = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
        if (IsEqual(d, 0))
            {
            roots_p->x1 = roots_p->x2 = -coeffs.b / (2 * coeffs.a);
            return ONE_ROOT;
            }
        else if (d > 0)
            {
            roots_p->x1 = (-coeffs.b - sqrt(d)) / (2 * coeffs.a);
            roots_p->x2 = (-coeffs.b + sqrt(d)) / (2 * coeffs.a);
            return TWO_ROOTS;
            }
        }

    return ZERO_ROOTS;
    }

RootsCount SolveLinear(const double k, const double b, double *x1_p)
    {
    /* Проверка ошибок */
    myAssert (isfinite(k));
    myAssert (isfinite(b));
    myAssert (x1_p != NULL);

    if (IsEqual(k, 0))
        {
        return (IsEqual(b, 0)) ? INF_ROOTS : ZERO_ROOTS;
        }
    else
        {
        *x1_p = -b / k;
        return ONE_ROOT;
        }
    }
