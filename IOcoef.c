#include <stdio.h>
#include <assert.h>
#include <math.h>

// #define INF_ROOTS -1 / Устарело
// const int kInfRoots = -1 / Можно так
// const int INF_ROOTS = -1 / или так
// Идеально ->
enum RootsCount
    {
    INF_ROOTS = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
    };

enum error
    {
    OK    = 0,
    ERROR = -1
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

void InputCoefsSTD(Coefs *coefs_p);
error OutputCoefsSTD(int nRoots, Roots *roots_p);

void InputCoefsSTD(Coefs *coefs_p)
    {
    assert (coefs_p != NULL);

    printf("# Square equation solver\n\n"); /* Описание программы */

    printf("# Enter a, b, c: "); /* Понятный для пользователя ввод */
    scanf("%lg %lg %lg",
        &(*coefs_p).a, &(*coefs_p).b, &(*coefs_p).c); /* Ввод коэфицентов */

    //errors? cppreference scanf printf
    }

error OutputCoefsSTD(const int nRoots, Roots *roots_p)
    {
    assert (std::isfinite(nRoots));
    assert (roots_p != NULL);

    switch (nRoots)
        {
        case ZERO_ROOTS:
                printf("No roots\n");
                break;
        case ONE_ROOT:
                printf("x = %.3lg\n", (*roots_p).x1);
                break;
        case TWO_ROOTS:
                printf("x1 = %.3lg, x2 = %.3lg\n",
                        (*roots_p).x1, (*roots_p).x2);
                break;
        case INF_ROOTS:
                printf("Any number\n");
                break;
        default:
                printf("main(): Error: nRoots = %d", nRoots);
                return ERROR;
        }

    return OK;
    }
