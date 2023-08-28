#ifndef __TEST__
#define __TEST__

/// @brief Успешность прохождения теста.
enum TestFeedback
    {
    TEST_FAILED  = 0, //!< Провал.
    TEST_ACEPTED = 1  //!< Успех.
    };

/// @brief Тестируемые данные.
struct TestData
    {
    Coeffs coeffs;        //!< Коэфиценты.
    RootsCount nRootsRef; //!< Ожидаемое колличество корней.
    Roots RootsRef;       //!< Ожидаемые корни.
    const char* name;     //!< Название теста.
    };

//!@brief Функция, тестирующая функцию SolveSquare.
TestFeedback TestOne(Coeffs coeffs, int nRootsRef, Roots RootsRef);

//!@brief Функция, которая, проводит серию тестов на основе данных из файла test.txt.
int TestAll();
#endif //__TEST__
