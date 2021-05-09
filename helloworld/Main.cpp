#include <iostream>
// #include "Adder/adder1.h"
#include "adder1.h"

float add(float a, float b);

int main(){
    std::cout << "Hello World" << std::endl;
    std::cout << add(12.34f, 34.12f) << std::endl;
    std::cout << adder1(12.34, 34.12) << std::endl;
    return 0;
}