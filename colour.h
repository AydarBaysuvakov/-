#ifndef __COLOUR_H__
#define __COLOUR_H__

enum Colour
    {
    BLACK   = 30,
    RED     = 31,
    GREEN   = 32,
    YELLOW  = 33,
    BLUE    = 34,
    MAGENTA = 35,
    CYAN    = 36,
    RESET   = 0
    };

void ColuredPrintf(Colour colour, const char* format, ...);
#endif // __COLOUR_H__
