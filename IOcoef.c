#include <stdio.h>
#include <assert.h>

enum ROOTS
    {
    INF_ROOTS = -1,
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
    };

// #define INF_ROOTS -1 / Устарело
// const int kInfRoots = -1 / Можно так
// const int INF_ROOTS = -1 / или так
// Идеально ->
enum error_lables
    {
    OK    = 0,
    ERROR = -1
    };
//a_p
error InputCoefsSTD(double *a, double *b, double *c)
    {
    assert (a != b);
    assert (b != c);
    assert (a != c);

    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    printf("# Square equation solver\n\n"); /* Описание программы */

    printf("# Enter a, b, c: "); /* Понятный для пользователя ввод */
    scanf("%lg %lg %lg", a, b, c); /* Ввод коэфицентов */

    //errors? cppreference scanf printf
    }

int OutputCoefsSTD(const int nRoots, const double x1, const double x2)
    {
    assert (isfinite(nRoots));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    switch (nRoots)
        {
        case ZERO_ROOTS:
                printf("No roots\n");
                break;
        case ONE_ROOT:
                printf("x = %.3lg\n", x1);
                break;
        case TWO_ROOTS:
                printf("x1 = %.3lg, x2 = %.3lg\n", x1, x2);
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
