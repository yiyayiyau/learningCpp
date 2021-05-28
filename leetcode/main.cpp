#include <iostream>
#include <string>

#include "ultilty.h"
#include "infTech.h"

void test(){
    // test_getVersion();
    // test_removeDuplicates();

    // test_removeDuplicates(removeDuplicates_STL);
    // test_removeDuplicates(removeDuplicates_STL1);
    
    // test_floatsAreEqual(10.0f/3.0f, 3.33f);
    // test_prifix_postfix();
    
    // test_isLeapYear(2021);

    // test_print_sizelimits();

    // test_getchar();
    // test_scanf();

    test_array();
    test_swap();

}

int main(int argc, char** argv)
{
    std::cout << "Hello LeetCode" << std::endl;

    test();

    std::cin.get();
    return 0;
}