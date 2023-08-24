void myAssert(int expr, const char file[], int line, const char* func);

#ifdef DEBUG
#define myAssert(expr) myAssert(expr, __FILE__, __LINE__, __FUNCTION__)
#else
#define myAssert(expr) ;
#endif
