#include <stdio.h>
#include <stdlib.h>
#include "colour.h"

void myAssert(int expr, const char* text, const char* file, int line, const char* func)
    {
    if (!expr)
        {
        printf( RED("О НЕТ, ТУПОЙ ПРОГРАММИСТ ЗАПОРОЛСЯ\nНЕ ПРОШЛО УСЛОВИЕ %s\nФАЙЛ ''%s''\nФУНКЦИЯ: %s\nСТРОКА: %d\u001b[0m\n"), text, file, func, line);
        exit(1);
        }
    }
