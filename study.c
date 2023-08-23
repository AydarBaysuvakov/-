#include "IOcoef.c"
#include "SolveFunc.c"

//sizeof(*)
//sizeof(char*) and sizeof(int*)

int main()
    {
    Coefs coefs = {0, 0, 0}; /* Инициализация */
    InputCoefsSTD(&coefs); /* Ввод коэфицентов */

    Roots roots = {0, 0}; /* Инициализируем корни когда это нужно */
    int nRoots = SolveSquare(coefs.a, coefs.b, coefs.c, &roots);
    /* Пишем вызов функции так, как нам удобно */

    return OutputCoefsSTD(nRoots, &roots); /* Вывод корней */
    }
