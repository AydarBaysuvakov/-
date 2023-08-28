#ifndef __FUNC__
#define __FUNC__
#include <math.h>

/// @brief Константы, отвечающие за колличество корней.
enum RootsCount
    {
    INF_ROOTS  = -1,  //!< Бесконечное колличество корней.
    ZERO_ROOTS = 0,   //!< Нет корней.
    ONE_ROOT   = 1,   //!< Один корень.
    TWO_ROOTS  = 2    //!< Два корня.
    };

/// @brief Коэфиценты уравнения.
struct Coeffs
    {
    double a; //!< Старший член.
    double b; //!< Член при х.
    double c; //!< Свободный член.
    };

/// @brief Корни уравнения.
struct Roots
    {
    double x1; //!< Первый корень(меньший).
    double x2; //!< Второй корень(больший).
    };

//!Функция для решения линейного уравнения вида kx + b = 0.
//!
//!@param[in] k, b Коэфиценты уравнения.
//!@param[out] x1 Корень уравнения.
//!
//!@return Колличество корней.
RootsCount SolveLinear(const double k, const double b, double *x1_p);

//!Функция для решения квадратного уравнения вида ax^2 + bx + c = 0.
//!
//!@param[in] coeffs Коэфиценты уравнения(coeffs.a, coeffs.b, coeffs.c).
//!@param[out] roots_p Указатель на корни уравнения(roots_p->x1, roots_p->x2).
//!
//!@return Колличество корней (ZERO_ROOTS=0, ONE_ROOT=1, TWO_ROOTS=2).
//!
//!@note Если колличество корней бесконечно, возвращает INF_ROOTS=-1.
RootsCount SolveSquare(Coeffs coeffs, Roots *roots_p);
#endif //__FUNC__
