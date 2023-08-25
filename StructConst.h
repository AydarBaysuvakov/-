#ifndef header
#define header
#include <math.h>

/// @brief Флаг ответа ввода-вывода
enum IOError
    {
    OK    = 0, //!< Успешный ввод или вывод
    ERROR = -1 //!< Неуспешный ввод или вывод
    };

/// @brief Константы, отвечающие за колличество корней
enum RootsCount
    {
    INF_ROOTS = -1, //!< Бесконечное колличество корней
    ZERO_ROOTS = 0, //!< Нет корней
    ONE_ROOT = 1,   //!< Один корень
    TWO_ROOTS = 2   //!< Два корня
    };

/// @brief Коэфиценты уравнения
struct Coeffs
    {
    double a; //!< Старший член
    double b; //!< Член при х
    double c; //!< Свободный член
    };

/// @brief Корни уравнения
struct Roots
    {
    double x1; //!< Первый корень(Меньший)
    double x2; //!< Второй корень(Больший)
    };

#endif
