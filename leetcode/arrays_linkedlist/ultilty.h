#pragma once
#include <vector>
#include <string>
#include <iostream>

#include <algorithm>

template <class T>
std::string vto_string(std::vector<T> &a_v);

int removeDuplicates(std::vector<int>& nums);

// template <class T>
void test_removeDuplicates();

int removeDuplicates_STL(std::vector<int> &nums);

int removeDuplicates_STL1(std::vector<int> &nums);
template<typename InIt, typename OutIt>
OutIt removeDuplicates_STL1(InIt first, InIt last, OutIt output);

std::string getVersion();
void test_getVersion();