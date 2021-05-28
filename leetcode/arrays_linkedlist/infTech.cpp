#include "infTech.h"

unsigned char floatsAreEqual(float f1, float f2)
{
    unsigned char a = (fabs(f1 - f2) <= 1E-10);
    return a;
}
void test_floatsAreEqual(float f1, float f2)
{
    auto a = floatsAreEqual(f1, f2);
    printf("Floats are equal? %u \n", a);
    // std::cout << "floatsAreEqual: " << std::to_string(a) << std::endl;
}

void test_prifix_postfix()
{
    int num1 = 6;
    num1++;
    int num2 = 6;
    ++num2;
    unsigned char isequ = (num1 == num2);
    printf("num1 is %d, num2 is %d, are equal? %u \n", num1, num2, isequ);
    for (int i = 0; i < 5; i++)
    {
        printf("i is %d \n", i);
    }
    for (int i = 0; i < 5; ++i)
    {
        printf("j is %d \n", i);
    }
}

/*@brief 判断是否为闰年
*/
unsigned char istSchaltjahr(int jahr)
{
    if (jahr % 4 != 0)
        return 0;
    else if (jahr % 100 == 0 && jahr % 400 != 0)
        return 0;
    else
        return 1;
}
unsigned char isLeapYear(int year)
{
    return istSchaltjahr(year);
}
void test_isLeapYear(int year)
{
    auto a = isLeapYear(year);
    printf("%i is Leap Year? %u \n", year, a);
}

void test_print_sizelimits()
{
    printf("A char is %d bytes large and ranges between %d and %d.\n",
           sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("A short is %d bytes large and ranges between %d and %d.\n",
           sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("An int is %d bytes large and ranges between %d and %d.\n",
           sizeof(int), INT_MIN, INT_MAX);
    printf("An unsigned int is %d bytes large and ranges between %u and %u.\n",
           sizeof(unsigned int), 0, UINT_MAX);
    printf("A long is %d bytes large and ranges between %ld and %ld.\n",
           sizeof(long), LONG_MIN, LONG_MAX);
    printf("An unsigned long is %d bytes large and ranges between %u and %u.\n",
           sizeof(unsigned long), 0, ULONG_MAX);
    printf("A float is %d bytes long, a double %ld bytes.\n",
           sizeof(float), sizeof(double));
}

void test_getchar()
{
    printf("Please give me a ziffer: ");
    char c = getchar();
    printf("The ziffer is: '%c'.\n", c);
}

int quadrat(int zahl)
{
    int ergebnis;
    ergebnis = zahl * zahl;
    return ergebnis;
}
void test_scanf()
{
    int ergebnis, zahl;
    printf("Programm zum Berechnen des Quadrats einer ganzen: \n");
    printf("Bitte geben Sie die Zahl ein:");
    scanf("%d", &zahl);
    printf("Die gegeben zahl ist: %d", zahl);
    ergebnis = quadrat(zahl);
    printf("Das Ergebnis ist: %d", ergebnis);
}

void print_array(int zahlen[]){
    for (int i = 0; i < 10; i++){
        printf("%d ", zahlen[i]);
    }
    printf("\n");
}
void test_array(){
    int natZahlen[10] = {0,1,2,3,4,5,6,7,8,9};
    print_array(natZahlen);
    
    int natZahlen1[10] = {0,1,2,3};
    print_array(natZahlen1);

    int natZahlen2[10] = {0};
    print_array(natZahlen2);

    int natZahlen3[10] = {1};
    print_array(natZahlen3);
}



void swap(int *i, int *j){
    auto tmp = *i;
    *i = *j;
    *j = tmp;
}
void test_swap(){
    int i = 3, j = 5;
    printf(" befor swap: %d, %d \n", i,j);
    swap(&i, &j);
    printf(" after swap: %d, %d \n", i,j);
}