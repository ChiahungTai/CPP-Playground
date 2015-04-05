// Ch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


class Sales_item {
};

int jj;
extern double pi = 3.1416;
int f = 42;
int i = 2;
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

  typedef double wages; // wages is a synonym for double
  typedef wages base, *p; // base is a synonym for double, p for double*

  p pointDouble = new double[20];
  delete pointDouble;

  using SI = Sales_item;
  wages hourly, weekly;
  SI item;

  const int ci = i, &cr = ci;
  auto bi = ci;
  auto co = cr;
  auto d = &i;
  auto e = &ci;

  auto &g = ci; // g is a const int& that is bound to ci
  // auto &h = 42; // error: we can't bind a plain reference to a literal
  const auto &j = 42; // ok: we can bind a const reference to a literal

  auto k = ci, &l = i; // k is int; l is int&
  auto &m = ci, *pig = &ci; // m is a const int&;p is a pointer to const int
  // error: type deduced from i is int; type deduced from &ci is const int
  // IntelliSense: 'auto' type is "const int" for this entity, but was previously implied to be "int"
  // auto &n = i, *p2 = &ci; //error C3538: in a declarator-list 'auto' must always deduce to the same type


	return 0;
}

