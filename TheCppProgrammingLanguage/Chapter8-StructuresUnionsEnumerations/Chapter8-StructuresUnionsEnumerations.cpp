// Chapter8-StructuresUnionsEnumerations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>

using std::ostream;
using std::array;

struct Point {
  int x, y;
};

Point points[3] {{1, 2}, { 3, 4 }, { 5, 6 }};
int x2 = points[2].x;
struct Array {
  Point elem[3];
};

// Array points2{ { 1, 2 }, { 3, 4 }, { 5, 6 } };
// MSVC bug, below is a work around.
Array points2{ { { 1, 2 }, { 3, 4 }, { 5, 6 } } };

int y2 = points2.elem[2].y;

Point point1[] = { { 1, 2 }, { 3, 4 }, { 5, 6 } }; // 3 elements
//array<Point, 3> point2 = { { 1, 2 }, { 3, 4 }, { 5, 6 } }; // 3 elements
// MSVC bug, below is a work around.
array<Point, 3> point2 = { { { 1, 2 }, { 3, 4 }, { 5, 6 } } }; // 3 elements
//array<Point> point3 = { { 1, 2 }, { 3, 4 }, { 5, 6 } }; // error : number of elements not given


ostream& operator<<(ostream& os, Point p)
{
  //Errata
  //cout << '{' << p[i].x << ',' << p[i].y << '}';
  return os << "{" << p.x << "," << p.y << "}";
}

template<typename T>
void mycopy(T* to, const T* from, int count)
{
  if (is_pod<T>::value)
    memcpy(to, from, count*sizeof(T));
  else
    for (int i = 0; i != count; ++i)
      to[i] = from[i];
}

struct PPN { // R6000 Physical Page Number
  unsigned int PFN : 22; // Page Frame Number
  int : 3; // unused
  unsigned int CCA : 3; // Cache Coherency Algorithm
  bool nonreachable : 1;
  bool dirty : 1;
  bool valid : 1;
  bool global : 1;
};

union U2 {
  int a;
  const char* p{ "" };
};
U2 x1; // default initialized to x1.p == ""
// MSVC bug, if we have default initializer, then below compile error.
// U2 xx2{ 7 }; // xx2.a == 7

struct MyStruct {
  int myInt;
  char myChar;
};
union MyUnion {
  int my_int;
  char my_char;
  bool my_bool;
  MyStruct my_struct;
};

MyUnion mu1{ 'a' };  // my_int = 97, my_char = 'a', my_bool = true, {myInt = 97, myChar = '\0'}
MyUnion mu2{ 1 };   // my_int = 1, my_char = 'x1', my_bool = true, {myInt = 1, myChar = '\0'}
MyUnion mu3{};      // my_int = 0, my_char = '\0', my_bool = false, {myInt = 0, myChar = '\0'}
MyUnion mu4 = mu3;  // my_int = 0, my_char = '\0', my_bool = false, {myInt = 0, myChar = '\0'}
//MyUnion mu5{ 1, 'a', true };  // compiler error: C2078: too many initializers
//MyUnion mu6 = 'a';            // compiler error: C2440: cannot convert from 'char' to 'MyUnion'
//MyUnion mu7 = 1;              // compiler error: C2440: cannot convert from 'int' to 'MyUnion'

MyStruct ms1{ 'a' };            // myInt = 97, myChar = '\0'
MyStruct ms2{ 1 };              // myInt = 1, myChar = '\0'
MyStruct ms3{};                 // myInt = 0, myChar = '\0'
MyStruct ms4{ 1, 'a' };           // myInt = 1, myChar = 'a'
MyStruct ms5 = { 2, 'b' };      // myInt = 2, myChar = 'b'

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

