#pragma once
#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
/*@brief Convert vector of numbers to string
* @a_v no-leer input vector
* @return string
*/
template <class T>
std::string vto_string(std::vector<T> &a_v);

/*@brief two pointes, first point to the last unduplicates number,
* second point to the loop-index.
* If two object are not same, first point move to the next and 
* copy the value from second point; if same, second pointer move 
* on.
*
* ------time complex O(n), space complex O(1)------
*
* @param nums sorted vector
* @return number of unduplicate numbers
*/
int removeDuplicates(std::vector<int>& nums);

// template <class T>
void test_removeDuplicates();
/*@brief Use STL-unique: remove consecutive (adjacent) duplicates.
*
* ------time complex O(n), space complex O(1)------
*/
int removeDuplicates_STL(std::vector<int> &nums);


int removeDuplicates_STL1(std::vector<int> &nums);
template<typename InIt, typename OutIt>
OutIt removeDuplicates_STL1(InIt first, InIt last, OutIt output);

/*@breif Get c++ version
*@return string of version
*/
std::string getVersion();
void test_getVersion();