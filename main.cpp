#include "StructConst.h"
#include "main.h"

int main()
    {
    #ifdef TEST
    TestAll();
    #else
    Coefs coefs = {0, 0, 0}; /* Инициализация */
    if (InputCoefsSTD(&coefs)) /* Ввод коэфицентов */ //coeffs
        {
        return ERROR;
        }

    Roots roots = {0, 0}; /* Инициализируем корни когда это нужно */
    int nRoots = SolveSquare(coefs, &roots);

    return OutputCoefsSTD(nRoots, &roots); /* Вывод корней */
    #endif
    }
