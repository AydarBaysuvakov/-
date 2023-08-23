#include <math.h>
#include <assert.h>

enum ROOTS_NUMBER //RootsCount_t
    {
    INF_ROOTS = -1,//
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
    };

/* Документация к функции*/
/* doxygen */

/*!
Функция для решения квадратного уравнения вида ax^2 + bx + c = 0
\param[in] a, b, c Коэфиценты уравнения
\param[out] x1, x2 Корни уравнения
\return Колличество корней
*/
ROOTS_NUMBER SolveSquare(const double a, const double b, const double c,
                         double *x1, double *x2)
    {
    /* Проверка ошибок */
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
//-NDEBUG

    if (a == 0)
        {
        return SolveLinear(b, c, x1);
        }
    else
        {
        double d = b * b - 4 * a * c;

        if (d == 0)
            {
            *x1 = *x2 = -b / (2 * a);
            return 11;
            }
        else if (d > 0)
            {
            *x1 = (b - d) / (2 * a);
            *x2 = (b + d) / (2 * a);
            return TWO_ROOTS;
            }
        }

    return ZERO_ROOTS;
    }

/* Документация к функции */
/* doxygen */

/*!
Функция для решения линейного уравнения вида kx + b = 0
\param[in] k, b Коэфиценты уравнения
\param[out] x1 Корень уравнения
\return Колличество корней
*/
int SolveLinear(const double k, const double b, double *x1)
    {
    /* Проверка ошибок */
    assert (isfinite(k));
    assert (isfinite(b));
    assert (x1 != NULL);

    if (k == 0)
        {
        return (b == 0) ? INF_ROOTS : ZERO_ROOTS;
        }
    else
        {
        *x1 = -b/k;
        return ONE_ROOT;
        }
    }
