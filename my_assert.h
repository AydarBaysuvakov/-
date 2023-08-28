#ifndef __MY_ASSERT__
#define __MY_ASSERT__

//!@brief Завершает работу программы и вызывает предупреждающее сообщение.
//!Функция создана для отлавливания ошибок программиста.
void myAssert(int expr, const char* text, const char file[], int line, const char* func);

#endif //__MY_ASSERT__

#ifdef DEBUG
#define myAssert(expr) myAssert(expr, #expr, __FILE__, __LINE__, __FUNCTION__)
#else  //DEBUG
#define myAssert(expr) ;
#endif //DEBUG
