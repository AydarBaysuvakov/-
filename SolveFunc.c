RootsCount SolveLinear(const double k, const double b, double *x1);
RootsCount SolveSquare(const double a, const double b, const double c,
                        Roots *roots_p);

/* Документация к функции*/
/* doxygen */

//--------------------------------------------------------------
//!Функция для решения квадратного уравнения вида ax^2 + bx + c = 0
//!
//!@param[in] a, b, c Коэфиценты уравнения
//!@param[out] roots_p Указатель на корни уравнения
//!
//!@return Колличество корней
//--------------------------------------------------------------

RootsCount SolveSquare(const double a, const double b, const double c,
                        Roots *roots_p)
    {
    /* Проверка ошибок */
    assert (std::isfinite(a));
    assert (std::isfinite(b));
    assert (std::isfinite(c));
    assert (roots_p != NULL);
//-NDEBUG

    if (a == 0)
        {
        return SolveLinear(b, c, &(*roots_p).x1);
        }
    else
        {
        double d = b * b - 4 * a * c;

        if (d == 0)
            {
            (*roots_p).x1 = (*roots_p).x2 = -b / (2 * a);
            return ONE_ROOT;
            }
        else if (d > 0)
            {
            (*roots_p).x1 = (b - d) / (2 * a);
            (*roots_p).x2 = (b + d) / (2 * a);
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

RootsCount SolveLinear(const double k, const double b, double *x1)
    {
    /* Проверка ошибок */
    assert (std::isfinite(k));
    assert (std::isfinite(b));
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
