#ifndef my_assert
#define my_assert

//!@brief Завершает работу программы и вызывает предупреждающее сообщение
//!Функция создана для отлавливания ошибок программиста
void myAssert(int expr, const char* text, const char file[], int line, const char* func);

#endif

#ifdef DEBUG
#define myAssert(expr) myAssert(expr, #expr, __FILE__, __LINE__, __FUNCTION__)
#else
#define myAssert(expr) ;
#endif
