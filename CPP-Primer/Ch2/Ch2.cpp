// Ch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = -42;
	unsigned u = 10;
	std::cout << i + i << std::endl;
	std::cout << i + u << std::endl;

	unsigned u1 = 42, u2 = 10;
	std::cout << u1 - u2 << std::endl;
	cout << u2 - u1 << endl;
	cout << "HI \x4dO\115!" << endl;
	cout << "\115\n";
	return 0;
}

