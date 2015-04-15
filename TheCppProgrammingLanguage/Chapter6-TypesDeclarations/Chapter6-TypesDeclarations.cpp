// Chapter6-TypesDeclarations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <cstdint>
#include <string>
#include <vector>
#include <complex>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::complex;

struct Date { int d, m, y; };
int day(Date* p) { return p->d; }
template<class T> T abs(T a) { return a<0 ? −a : a; }


int _tmain(int argc, _TCHAR* argv[])
{
	cout << 0xF0UL << ' ' << 0LU << '\n';
	cout << 10e-4 << ' ' << R"(\b)" << '\n';
	cout << 31415e-4 << '\n';

	cout << "size of long " << sizeof(1L) << endl;
	cout << "size of long long " << sizeof(1Ll) << endl;

	cout << "largest float == " << std::numeric_limits<float>::max() << endl;
	cout << "char is signed == " << (std::numeric_limits<char>::is_signed ? "true" : "false") << endl;

  // you need to include <cstdint>
  int16_t x{ (int16_t)0xaabb }; // 2 bytes
  int64_t xxxx{ (int64_t)0xaaaabbbbccccdddd }; // 8 bytes
  int_least16_t y; // at least 2 bytes (just like int)
  int_least32_t yy; // at least 4 bytes (just like long)
// Not supported now.
//  int_fast32_t z; // the fastest int type with at least 4 bytes

  // C++0x
  //auto ac = alignof('c'); // the alignment of a char
  //auto ai = alignof(1); // the alignment of an int
  //auto ad = alignof(2.0); // the alignment of a double
  //int a[20];
  //auto aa = alignof(a); // the alignment of an int

  char ch;
  string s;
  auto count = 1;
  const double pi{ 3.1415926535897 };
  extern int error_number;
  const char *name = "Njal";
  const char *season[] = { "spring", "summer", "fall", "winter" };
  vector<string> people{ name, "Skarphedin", "Gunnar" };

  double sqrt(double);
  // Not supported yet.
  //constexpr int fac(int n) { return (n<2) ? 1 : n*fac(n−1); } // possible compile-time evaluation (§2.2.3)
  //constexpr double zz{ ii*fac(7) }; // compile-time initialization
  using Cmplx = std::complex<double>; // type alias (§3.4.5, §6.5)
  struct User; // type name
  enum class Beer { Carlsberg, Tuborg, Thor };

  auto z1{ 99 }; // z1 is an initializer_list<int>
  auto z2 = 99; // z2 is an int

  vector<int> v1{ 99 }; // v1 is a vector of 1 element with the value 99
  vector<int> v2(99); // v2 is a vector of 99 elements each with the default value 0
  vector<string> v12{ "hello!" }; // v1 is a vector of 1 element with the value "hello!"
//  vector<string> v12("hello!"); // error : no vector constructor takes a string literal

  return 0;
}

namespace NS { int a; }

void f(double val, int val2)
{
  int x2 = val; // if val==7.9, x2 becomes 7
  char c2 = val2; // if val2==1025, c2 becomes 1
//  int x3{ val }; // error : possible truncation
//  char c3{ val2 }; // error : possible narrowing
  char c4{ 24 }; // OK: 24 can be represented exactly as a char
//  char c5{ 264 }; // error (assuming 8-bit chars): 264 cannot be represented as a char
//  int x4{ 2.0 }; // error : no double to int value conversion
  // ...
}

void f2()
{
  int x; // x does not have a well-defined value
  char buf[1024]; // buf[i] does not have a well-defined value
  int* p{ new int }; //*p does not have a well-defined value
  char* q{ new char[1024] }; // q[i] does not have a well-defined value
  string s; // s=="" because of string’s default constructor
  vector<char> v; // v=={} because of vector’s default constructor
  string* ps{ new string }; // *ps is "" because of string’s default constructor
  // ...
}

void ff()
{
  int x{}; // x becomes 0
  char buf[1024]{}; // buf[i] becomes 0 for all i
  int* p{ new int{ 10 } }; // *p becomes 10
  char* q{ new char[1024]{} }; // q[i] becomes 0 for all i
  // ...
}

template<class T> void f3(vector<T>& arg)
{
  for (vector<T>::iterator p = arg.begin(); p != arg.end(); ++p)
    *p = 7;
  for (auto p = arg.begin(); p != arg.end(); ++p)
    *p = 7;
}

void g(int& v)
{
  auto x = v; // x is an int (not an int&)
  auto& y = v; // y is an int&
}

string f() { return string("WTF"); }

void auto_1(){
  auto v1 = 12345; // v1 is an int
  auto v2 = 'c'; // v2 is a char
  auto v3 = f(); // v3 is of some appropriate type
}

void auto_2(){
  auto v1{ 12345 }; // v1 is a list of int
  auto v2{ 'c' }; // v2 is a list of char
  auto v3{ f() }; // v3 is a list of some appropriate type
}

void auto_3(){
//  auto x0{}; // error : cannot deduce a type
  auto x1{ 1 }; // list of int with one element
  auto x2{ 1, 2 }; // list of int with two elements
  auto x3{ 1, 2, 3 }; // list of int with three elements
}

template<class T, class U>
complex<decltype(T{}+U{})> operator+(const complex<T>& a, const complex<U>& b)
{
  Matrix<decltype(T{}+U{})> res;
  for (int i = 0; i != a.rows(); ++i)
    for (int j = 0; j != a.cols(); ++j)
      res(i, j) += a(i, j) + b(i, j);
  return res;
}

using Pchar = char*; // pointer to character
using PF = int(*)(double); // pointer to function taking a double and returning an int
template<class T>
class vector1 {
  using value_type = T; // every container has a value_type
  // ...
};
template<class T>
class list1 {
  using value_type = T; // every container has a value_type
  // ...
};

typedef int int32_t; // equivalent to ‘‘using int32_t = int;’’
typedef short int16_t; // equivalent to ‘‘using int16_t = short;’’
typedef void(∗PtoF)(int); // equivalent to ‘‘using PtoF = void(*)(int);’’

template<typename T>
class My_allocator{
public:
  char* createBuffer(){ return nullptr; };
private:
  char* buffer;
};

template<typename T>
using Vector = std::vector<T, My_allocator<T>>;

using Char = char;
//using Uchar = unsigned Char; // error
using Uchar = unsigned char; // OK


