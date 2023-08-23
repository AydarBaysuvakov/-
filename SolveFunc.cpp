#include "header.h"

RootsCount SolveLinear(const double k, const double b, double *x1_p);
RootsCount SolveSquare(Coefs coefs, Roots *roots_p);
int IsEqual(double a, double b);

/* Документация к функции*/
/* doxygen */

//--------------------------------------------------------------
//!Функция для решения квадратного уравнения вида ax^2 + bx + c = 0
//!
//!@param[in] coefs Коэфиценты уравнения(coefs.a, coefs.b, coefs.c)
//!@param[out] roots_p Указатель на корни уравнения
//!
//!@return Колличество корней
//--------------------------------------------------------------

RootsCount SolveSquare(Coefs coefs, Roots *roots_p)
    {
    /* Проверка ошибок */
    assert (isfinite(coefs.a));
    assert (isfinite(coefs.b));
    assert (isfinite(coefs.c));
    assert (roots_p != NULL);
    //-NDEBUG

    if (IsEqual(coefs.a, 0))
        {
        return SolveLinear(coefs.b, coefs.c, &roots_p->x1);
        }
    else
        {
        double d = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
        if (IsEqual(d, 0))
            {
            roots_p->x1 = roots_p->x2 = -coefs.b / (2 * coefs.a);
            return ONE_ROOT;
            }
        else if (d > 0)
            {
            roots_p->x1 = (coefs.b - sqrt(d)) / (2 * coefs.a);
            roots_p->x2 = (coefs.b + sqrt(d)) / (2 * coefs.a);
            return TWO_ROOTS;
            }
        }

    return ZERO_ROOTS;
    }

/* Документация к функции */
/* doxygen */

///----------------------------------------------------
//!Функция для решения линейного уравнения вида kx + b = 0
//!
//!@param[in] k, b Коэфиценты уравнения
//!@param[out] x1 Корень уравнения
//!
//!@return Колличество корней
///----------------------------------------------------

RootsCount SolveLinear(const double k, const double b, double *x1_p)
    {
    /* Проверка ошибок */
    assert (isfinite(k));
    assert (isfinite(b));
    assert (x1_p != NULL);

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
