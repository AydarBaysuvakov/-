#ifndef is_equal
#define is_equal
const double MEASURE_ERROR = 0.000001; //!< Погрешность

//!@brief Сравнивает действительные числа с учетом погрешности
//!
//!@param[in] a, b Сравниваемые числа
//!
//!@return True, если a и b равны, иначе False
int IsEqual(double a, double b);
#endif
