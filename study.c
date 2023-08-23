#include "IOcoef.c"
#include "SolveFunc.c"
//struct
//
int SolveSquare(const double a, const double b, const double c,
                double *x1, double *x2);
int SolveLinear(const double k, const double b, double *x1);
void InputCoefsSTD(double *a, double *b, double *c);
int OutputCoefsSTD(const int nRoots, const double x1, const double x2);

//sizeof(*)
//sizeof(char*) and sizeof(int*)
//
/* Пишем сначала main так, будто все функции уже есть, затем пишем нужные функции */
int main()
    {
    double a = 0, b = 0, c = 0; /* Инициализация нулем во избежание ошибок */
    InputCoefsSTD(&a, &b, &c); /* Ввод коэфицентов */

    double x1 = 0, x2 = 0; /* Инициализируем корни когда это нужно */
    int nRoots = SolveSquare(a, b, c, &x1, &x2); /* Пишем вызов функции так, как нам удобно */

    /* Вывод корней */
    return OutputCoefsSTD(nRoots, x1, x2);
    }
