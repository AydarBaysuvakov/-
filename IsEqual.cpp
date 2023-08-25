#include <math.h>
#include "assert.h"

const double MEASURE_ERROR = 0.000001; //!< Погрешность

//! Булевый тип данных
enum boolean
    {
    False = 0, //!< Ложь(0)
    True = 1   //!< Истина(1)
    };

//!@brief Сравнивает действительные числа с учетом погрешности
//!
//!@param[in] a, b Сравниваемые числа
//!
//!@return True, если a и b равны, иначе False
boolean IsEqual(double a, double b)
    {
    myAssert(isfinite(a));
    myAssert(isfinite(b));

    if (abs(a - b) <= MEASURE_ERROR)
        {
        return True;
        }
    return False;
    }
