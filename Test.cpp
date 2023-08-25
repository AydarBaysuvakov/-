#include <stdio.h>
#include <ctype.h>
#include "StructConst.h"
#include "solve.h"
#include "assert.h"
#include "colour.h"

enum TestFeedback
    {
    TestFailed = 0,
    TestAcepted = 1
    };

struct TestData
    {
    Coeffs coeffs = {0, 0, 0};
    int nRootsRef = 0;
    Roots RootsRef = {0, 0};
    const char* name = "test";
    };

///-------------------------------------------------------
//!@brief Функция, тестирующая функцию SolveSquare
///-------------------------------------------------------

TestFeedback TestOne(Coeffs coeffs, int nRootsRef, Roots RootsRef)
    {
    myAssert(isfinite(coeffs.a));
    myAssert(isfinite(coeffs.b));
    myAssert(isfinite(coeffs.c));
    myAssert(isfinite(nRootsRef));
    myAssert(isfinite(RootsRef.x1));
    myAssert(isfinite(RootsRef.x2));

    Roots roots = {0, 0};
    int nRoots = SolveSquare(coeffs, &roots);

    if (!IsEqual(roots.x1, RootsRef.x1) or !IsEqual(roots.x2, RootsRef.x2))
        {
        printf(RED("ERROR: x1 = %lg, x2 = %lg, nRoots = %d\n\tEXCEPTED:  x1 = %lg, x2 = %lg, nRoots = %d\n"),
        roots.x1, roots.x2, nRoots,
        RootsRef.x1, RootsRef.x2, nRootsRef);
        return TestFailed;
        }
    else
        {
        printf(GREEN("OK\n"));
        return TestAcepted;
        }
    }

int TestAll()
    {
    int nTestAcepted = 0;
    int TestNumber = 0;

    char fname[] = "test.txt";
    char mode[] = "r";
    FILE *fp = fopen(fname, mode); // error

    TestData test;

    while (fscanf(fp, "%lg %lg %lg %d %lg %lg",
                  &test.coeffs.a, &test.coeffs.b, &test.coeffs.c,
                  &test.nRootsRef, &test.RootsRef.x1,
                  &test.RootsRef.x2) != EOF)
        {

        TestNumber++;
        char c = '\0';
        while ((c = getc(fp)) != '\n')
            {
            if (!isspace(c))
                {
                printf(YELLOW("Внимание: Ошибка теста\nНомер теста: %d\n"), TestNumber);
                printf(YELLOW("Пройдено %d тестов из %d\n"), nTestAcepted, TestNumber);
                return nTestAcepted;
                }
            }

        printf("TEST № %d: ", TestNumber);
        nTestAcepted += TestOne(test.coeffs, test.nRootsRef, test.RootsRef);
        }

    printf(YELLOW("Пройдено %d тестов из %d\n"), nTestAcepted, TestNumber);
    return nTestAcepted;
    }
