// Ch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int jj;
extern double pi = 3.1416;
int f = 42;
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int i = -42;
	unsigned u = 10;
	std::cout << i + i << std::endl;
	std::cout << i + u << std::endl;

	unsigned u1 = 42, u2 = 10;
	std::cout << u1 - u2 << std::endl;
	cout << u2 - u1 << endl;
	cout << "HI \x4dO\115!" << endl;
	cout << "\115\n";
	*/
	int units_sold0 = 0;
	int units_sold1 = {1};
	int units_sold2(2);
	int units_sold3{3};

	long double ld = 3.1415926536;
	// int a{ld}; // error C2397: conversion from 'long double' to 'int' requires a narrowing conversion
	int b(ld);
	int c = ld;
	
	extern int i; // declares but does not define i
	int jk; // declares and defines jk
	
//	printf("i = %d", i); //error LNK2001: unresolved external symbol "int i" (?i@@3HA)
//	printf("jk = %d", j); //rutime check error
	printf("jj = %d", jj);

// 	extern double pi = 3.1416; //error C2205: 'pi' : cannot initialize extern variables with block scope  
	int f = 100;
	int z = ::f;

	int ival = 1024;
	int& refval = ival;
//	int& refval2; //error C2530: 'refval2' : references must be initialized

	int ik = 42;
	int* pik;
	int*& rpik = pik;
	rpik = &ik;
	*rpik = 0;

	/* Not support in VS2013
	constexpr int *np = nullptr; // np is a constant pointer to int that is	null
	int j = 0;
	constexpr int i = 42; // type of i is const int
	// i and j must be defined outside any function
	constexpr const int *p = &i; // p is a constant pointer to the const int i
	constexpr int *p1 = &j; // p1 is a constant pointer to the int j
	*/
	return 0;
}

