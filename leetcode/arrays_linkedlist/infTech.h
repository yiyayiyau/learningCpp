#include <stdio.h> // printf, getchar
#include <math.h> // fabs
#include <limits.h> // print size limit of char


unsigned char floatsAreEqual(float f1, float f2);
void test_floatsAreEqual(float f1, float f2);

void test_prifix_postfix();

unsigned char istSchaltjahr(int jahr);
unsigned char isLeapYear(int year);
void test_isLeapYear(int year);

void test_print_sizelimits();

void test_getchar();

int quadrat(int zahl);
/*@brief scanf %d 可以接收字母，但会转成编码; 可以输入多个数字，用空格隔开*/
void test_scanf();


void print_array(int zahlen[]);
/* Array bsp*/
void test_array();

/* @brief pointer and adress -- call by reference -- bsp swap
* @param i : input as point, *i means the value in this adress
*/
void swap(int *i, int *j);
/*@brief call by reference, swap 3 and 5*/
void test_swap();