#include "header.h"

int InputCoefsSTD(Coefs *coefs_p);
int OutputCoefsSTD(int nRoots, Roots *roots_p);
int SolveSquare(Coefs coefs, Roots *roots_p);
int TestAll();

int main()
    {
    #ifdef TEST
    TestAll();
    #else
    Coefs coefs = {0, 0, 0}; /* Инициализация */
    if (InputCoefsSTD(&coefs)) /* Ввод коэфицентов */
        {
        return ERROR;
        }

    Roots roots = {0, 0}; /* Инициализируем корни когда это нужно */
    int nRoots = SolveSquare(coefs, &roots);

    return OutputCoefsSTD(nRoots, &roots); /* Вывод корней */
    #endif
    }
