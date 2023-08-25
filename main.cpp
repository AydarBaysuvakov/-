#include "StructConst.h"
#include "main.h"

int main()
    {
    #ifdef TEST
    TestAll();
    #else
    Coeffs coeffs = {0, 0, 0}; /* Инициализация */
    if (InputCoeffsSTD(&coeffs)) /* Ввод коэфицентов */ //coeffs
        {
        return ERROR;
        }

    Roots roots = {0, 0}; /* Инициализируем корни когда это нужно */
    int nRoots = SolveSquare(coeffs, &roots);

    return OutputCoeffsSTD(nRoots, &roots); /* Вывод корней */
    #endif
    }
