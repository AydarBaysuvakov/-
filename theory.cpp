#include <stdio.h>
#include <cstdint>

struct point {
    int x;
    int y;
    } pt;

struct Strange {
   char a;
   int32_t b;
};

int main(){
    printf("int %ld\n", sizeof(int));
    printf("int* %ld\n", sizeof(int*));
    printf("char %ld\n", sizeof(char));
    printf("char* %ld\n", sizeof(char*));
    printf("short %ld\n", sizeof(short));
    printf("short* %ld\n", sizeof(short*));
    printf("long %ld\n", sizeof(long));
    printf("long* %ld\n", sizeof(long*));
    printf("float %ld\n", sizeof(float));
    printf("float* %ld\n", sizeof(float*));
    printf("double %ld\n", sizeof(double));
    printf("double* %ld\n", sizeof(double*));
    printf("ld %ld\n", sizeof(long double));
    printf("ld* %ld\n", sizeof(long double*));
    printf("int[] %ld\n", sizeof(int[3]));
    printf("double[] %ld\n", sizeof(double[3]));
    printf("char[] %ld\n", sizeof(char[3]));
    printf("struct %ld\n", sizeof(point));
    printf("struct* %ld\n", sizeof(point*));
    printf("str obj %ld\n", sizeof(pt));
    printf("str param %ld\n", sizeof(pt.x));
    printf("strange %ld\n", sizeof(Strange));
    }
