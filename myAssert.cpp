#include <stdio.h>
#include <stdlib.h>
#include "colour.h"

void myAssert(int expr, const char* file, int line, const char* func)
    {
    if (!expr)
        {
        printf( RED("О НЕТ, ТУПОЙ ПРОГРАММИСТ ЗАПОРОЛСЯ\nФАЙЛ ''%s''\nФУНКЦИЯ: %s\nСТРОКА: %d\u001b[0m\n"), file, func, line);
        exit(1);
        }
    }
