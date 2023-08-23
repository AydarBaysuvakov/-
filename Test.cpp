#include <stdio.h>
#include "header.h"

enum TestFeedback
    {
    TestFailed = 0,
    TestAcepted = 1
    };

int SolveSquare(Coefs coefs, Roots *roots_p);
int IsEqual(double a, double b);

TestFeedback TestOne(Coefs coefs, int nRootsRef, Roots RootsRef)
    {
    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));
    assert(isfinite(nRootsRef));
    assert(isfinite(RootsRef.x1));
    assert(isfinite(RootsRef.x2));

    Roots roots = {0, 0};
    int nRoots = SolveSquare(coefs, &roots);

    if (!IsEqual(roots.x1, RootsRef.x1) or !IsEqual(roots.x2, RootsRef.x2))
        {
        printf("ERROR: x1 = %lg, x2 = %lg, nRoots = %d\nEXCEPTED:  x1 = %lg, x2 = %lg, nRoots = %d\n",
        roots.x1, roots.x2, nRoots,
        RootsRef.x1, RootsRef.x2, nRootsRef);
        return TestFailed;
        }
    else
        {
        printf("OK\n");
        return TestAcepted;
        }
    }

int TestAll()
    {
    int nTestAcepted = 0;

    char fname[] = "test.txt";
    char mode[] = "r";
    FILE *fp = fopen(fname, mode); // error

    Coefs coefs = {0, 0, 0};
    int nRootsRef = 0;
    Roots RootsRef = {0, 0};

    while (fscanf(fp, "%lg %lg %lg %d %lg %lg",
                  &coefs.a, &coefs.b, &coefs.c,
                  &nRootsRef, &RootsRef.x1, &RootsRef.x2) != EOF)
        {
        nTestAcepted += TestOne(coefs, nRootsRef, RootsRef);
        }

    return nTestAcepted;
    }
