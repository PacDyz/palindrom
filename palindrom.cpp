// palindrom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <iterator>

//some namespace
template <typename Container>
auto mid(const Container& container)
{
	auto half_distance = std::distance(std::begin(container),
		std::end(container)) / 2;
	return std::next(container.begin(), half_distance);
}

bool is_palindrome(const std::string& str) {
	return std::equal(str.cbegin(), mid(str), str.crbegin(),
		[](unsigned char lhs, unsigned char rhs) {
		return std::tolower(lhs) == std::tolower(rhs);
	});
}

int main()
{
	std::string str{ "KArak" };
	std::cout << std::boolalpha;
	std::cout << "is \"KArak\" palindrome? " << is_palindrome(str) << '\n';
	std::cout << "is \"fuf\" palindrome? " << is_palindrome("fuf") << '\n';
	std::cout << "is empty string palindrome? " << is_palindrome("") << '\n';
	return 0;
}