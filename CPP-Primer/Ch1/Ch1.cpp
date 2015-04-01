// Ch1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sales_item.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2
		<< " is: " << v1 + v2 << std::endl;
	int sum = 0, val = 1;
	while ( val <= 10) {
		sum += val;
		++val;
	}
	std::cout << "sum of 1-10 = " << sum << std::endl;

	sum = 0;
	for (size_t ix = 1; ix <= 10; ++ix) {
		sum += ix;
	}
	std::cout << "sum of 1-10 = " << sum << std::endl;
	int sum = 0, value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "sum is: " << sum << std::endl;

	int currVal = 0, val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (currVal == val) {
				++cnt;
			}
			else {
				std::cout << currVal << " occurs "
					<< cnt << "times." << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs "
			<< cnt << " times." << std::endl;

	}
	*/
	/*
	Sales_item book;
	std::cin >> book;
	std::cout << book << std::endl;

	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn()) {
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	std::cerr << "Data must refer to the same ISBN" << std::endl;
	return -1;
	*/
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			} else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}

