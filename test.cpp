#include <stdio.h>
#include <ctype.h>
#include "solving_functions.h"
#include "my_assert.h"
#include "colour.h"
#include "test.h"
#include "is_equal.h"


TestFeedback TestOne(Coeffs coeffs, RootsCount nRootsRef, Roots RootsRef)
    {
    myAssert(isfinite(coeffs.a));
    myAssert(isfinite(coeffs.b));
    myAssert(isfinite(coeffs.c));
    myAssert(isfinite(RootsRef.x1));
    myAssert(isfinite(RootsRef.x2));

    Roots roots = {0, 0};
    RootsCount nRoots = SolveSquare(coeffs, &roots);

    if (!IsEqual(roots.x1, RootsRef.x1) || !IsEqual(roots.x2, RootsRef.x2))
        {
        printf(RED("ERROR: x1 = %lg, x2 = %lg, nRoots = %d\n\tEXCEPTED:  x1 = %lg, x2 = %lg, nRoots = %d\n"),
        roots.x1, roots.x2, nRoots,
        RootsRef.x1, RootsRef.x2, nRootsRef);
        return TEST_FAILED;
        }
    else
        {
        printf(GREEN("OK\n"));
        return TEST_ACEPTED;
        }
    }

int TestAll()
    {
    int nTestAcepted = 0;
    int TestNumber = 0;

    char fname[] = "test.txt";
    char mode[] = "r";
    FILE *fp = fopen(fname, mode);

    TestData test { {0, 0, 0}, 0, {0, 0}, "test" };

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
                //printf_colored(COLOR_YELLOW, "adsfads", fasd , asdf,asdf ); va_arg va_list
                printf(YELLOW("Внимание: Ошибка теста\nНомер теста: %d\n"), TestNumber);
                printf(YELLOW("Пройдено %d тестов из %d\n"), nTestAcepted, TestNumber);
                return nTestAcepted;
                }
            }

        printf("TEST № %d: ", TestNumber);
        nTestAcepted += TestOne(test.coeffs, test.nRootsRef, test.RootsRef);
        }

    printf(GREEN("Пройдено %d тестов из %d\n"), nTestAcepted, TestNumber);
    return nTestAcepted;
    }
