#include <stdio.h>
#include <ctype.h>
#include "StructConst.h"
#include "assert.h"

///-------------------------------------------------------------------
//!@brief Запрашивает коэффиценты квадратного уравнения вида ax^2 + bx + c = 0
//!
//!На первой строке выводится информация о программе
//!На второй строке выводится просьба ввести коэфиценты
//!Далее пользователь должен ввести три действительных числа, коэффиценты a, b, c
//!
//!@return OK=0, если пользователь вводит верные данные, при ошибке выводит ERROR=1
///-------------------------------------------------------------------

IOError InputCoeffsSTD(Coeffs *coeffs_p)
    {
    myAssert(coeffs_p != NULL);

    printf("# Square equation solver\n\n"); /* Описание программы */

    printf("# Enter a, b, c: "); /* Понятный для пользователя ввод */
    scanf("%lg %lg %lg", &coeffs_p->a, &coeffs_p->b, &coeffs_p->c);

    char c = '\0';
    while ((c = getchar()) != '\n')
        {
        if (isspace(c))
            {
            continue;
            }
        else
            {
            printf("Ошибка ввода\n");
            return ERROR;
            }
        }
    return OK;
    }


///----------------------------------------------------------
//!@brief Выводит корни квадратного уравнения вида ax^2 + bx + c = 0
//!
//!Печатает корни, если они есть
//!No roots, если корней нет
//!Any number, если все корнем уравнения является любое число
//!
//!@return выводит ERROR=1 при ошибке или OK=0, если ошибок нет
///----------------------------------------------------------

IOError OutputCoeffsSTD(const int nRoots, Roots *roots_p)
    {
    myAssert (isfinite(nRoots));
    myAssert (roots_p != NULL);

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
