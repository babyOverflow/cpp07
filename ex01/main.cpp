#include <string>
#include <iostream>
#include "iter.h"

int test_string(std::string s)
{
	std::cout << s << std::endl;
	return 1;
}

void test_string_void(std::string s)
{
	std::cout << s << std::endl;
}

int main()
{
	std::string s_arr[5] = {"123", "", "134", "aaaaaaaaaaa", "5"};
	iter(s_arr, 5, test_string);
	iter(s_arr, 5, test_string_void);
}