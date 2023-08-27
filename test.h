#ifndef ttt
#define ttt

/// @brief Успешность прохождения теста
enum TestFeedback
    {
    TestFailed = 0, //!< Провал
    TestAcepted = 1 //!< Успех
    };

/// @brief Тестируемые данные
struct TestData
    {
    Coeffs coeffs;      //!< Коэфиценты
    int nRootsRef;      //!< Ожидаемое колличество корней
    Roots RootsRef;     //!< Ожидаемые корни
    const char* name;   //!< Название теста
    };

//!@brief Функция, тестирующая функцию SolveSquare
TestFeedback TestOne(Coeffs coeffs, int nRootsRef, Roots RootsRef);

//!@brief
int TestAll();
#endif
