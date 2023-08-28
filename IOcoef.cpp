#include <stdio.h>
#include <ctype.h>
#include "my_assert.h"
#include "solving_functions.h"
#include "IOcoef.h"

IOError InputCoeffsSTD(Coeffs* coeffs_p)
    {
    myAssert(coeffs_p != NULL);

    printf("# Square equation solver\n\n"); /* Описание программы */

    printf("# Enter a, b, c: "); /* Понятный для пользователя ввод */
    scanf("%lg %lg %lg", &coeffs_p->a, &coeffs_p->b, &coeffs_p->c);

    for (char c = getchar(); c != '\n'; c = getchar())
        {
        if (!isspace(c))
            {
            printf("Ошибка ввода\n");
            return ERROR;
            }
        }

    return OK;
    }

IOError OutputCoeffsSTD(const RootsCount nRoots, Roots *roots_p)
    {
    myAssert (roots_p != NULL);

    switch (nRoots)
        {
        case ZERO_ROOTS:
                printf("No roots\n");
                break;
        case ONE_ROOT:
                printf("x = %.3lg\n", roots_p->x1);
                break;
        case TWO_ROOTS:
                printf("x1 = %.3lg, x2 = %.3lg\n",
                        roots_p->x1, roots_p->x2);
                break;
        case INF_ROOTS:
                printf("Any number\n");
                break;
        default:
                myAssert(!"ERROR");
                return ERROR;
        }

    return OK;
    }
