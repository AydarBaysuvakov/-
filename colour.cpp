#include <stdio.h>
#include <stdarg.h>
#include "colour.h"
#include "my_assert.h"

void ColuredPrintf(Colour colour, const char* format, ...)
    {
    myAssert(format != NULL)

    va_list arg_p;
    char *sval, cval;
    int ival;
    double dval;
    long int lval;

    va_start(arg_p, format);
    printf("\u001b[" "%d" "m", colour);
    for (; *format; format++) {
        if (*format != '%') {
            putchar(*format);
            continue;
        }
        switch (*++format) {
        case 'c':
            cval = va_arg(arg_p, int);
            putchar(cval);
            break;
        case 'd': case 'i':
            ival = va_arg(arg_p, int);
            printf ("%d", ival);
            break;
        case 'f': case 'F': case 'g': case 'G':
            dval = va_arg(arg_p, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(arg_p, char *); *sval; sval++)
            putchar(*sval);
            break;
        case 'l':
            if (*(format + 1) == 'g' || *(format + 1) == 'G' || *(format + 1) == 'f' || *(format + 1) == 'F')
                {
                dval = va_arg(arg_p, double);
                printf("%lg", dval);
                format++;
                break;
                }
            else if (*(format + 1) == 'd' || *(format + 1) == 'i')
                {
                lval = va_arg(arg_p, long int);
                printf("%ld", lval);
                format++;
                break;
                }
        default:
            putchar(*format);
            break;
        }
    }
    printf("\u001b[0m");
    va_end(arg_p);
    }
