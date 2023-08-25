#include "IOcoef.h"
#include "solving_functions.h"
#include "test.h"

int main()
    {
    #ifdef TEST
    TestAll();
    #else
    Coeffs coeffs = {0, 0, 0}; /* Инициализация */
    if (InputCoeffsSTD(&coeffs)) /* Ввод коэффицентов */
        {
        return ERROR;
        }

    Roots roots = {0, 0}; /* Инициализируем корни когда это нужно */
    int nRoots = SolveSquare(coeffs, &roots);

    return OutputCoeffsSTD(nRoots, &roots); /* Вывод корней */
    #endif
    }
