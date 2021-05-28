#include "ultilty.h"

template <class T>
std::string vto_string(std::vector<T> &a_v){  
    std::string ss = "{ ";
    for (int n : a_v)
    {
        ss += std::to_string(n);
        ss += ", ";
    }
    ss.erase(ss.end() - 2, ss.end());
    ss += " }";
    return ss;
}

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int index = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[index] != nums[i])
        {
            nums[++index] = nums[i];
        }
    }
    return index + 1;
}

int removeDuplicates_STL(std::vector<int> &nums){
    auto b = unique(nums.begin(), nums.end() );
    return distance( nums.begin(), b );
}

int removeDuplicates_STL1(std::vector<int> &nums){
    return distance(nums.begin(), removeDuplicates_STL1(nums.begin(),nums.end(),nums.begin()));
}
template<typename InIt, typename OutIt>
OutIt removeDuplicates_STL1(InIt first, InIt last, OutIt output){
    while (first != last){
        *output++ = *first;
        first = upper_bound(first, last, *first);
    }
    return output;
}

/*@brief input {3, 5, 5, 7, 10, 10, 10, 22, 25}
*@return { 3, 5, 7, 10, 22, 25, 10, 22, 25 };
*/
// template <class T>
void test_removeDuplicates()
{
    std::vector<int> a_v = {3, 5, 5, 7, 10, 10, 10, 22, 25};
    
    // with or not with <>, both are correct
    std::cout << "input is: " + vto_string(a_v) << std::endl;

    // int a = removeDuplicates(a_v);
    // int a = removeDuplicates_STL(a_v);
    int a = removeDuplicates_STL1(a_v);

    std::cout << "after removeDuplicates_STL1 is: " + 
        vto_string(a_v) << std::endl;
    // output: a_v = { 3, 5, 7, 10, 22, 25, 10, 22, 25, };

    std::cout << "length of output is: " + std::to_string(a) <<
     std::endl;
}


std::string getVersion()
{
    std::string s;
    if (__cplusplus == 201703L)
        s = "C++17\n";
    else if (__cplusplus == 201402L)
        s = "C++14\n";
    else if (__cplusplus == 201103L)
        s = "C++11\n";
    else if (__cplusplus == 199711L)
        s = "C++98\n";
    else
        s = "pre-standard C++\n";
    return s;
}

void test_getVersion()
{
    std::string s = getVersion();
    std::cout << s << std::endl;
}