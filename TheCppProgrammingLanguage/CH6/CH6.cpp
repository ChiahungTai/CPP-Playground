// CH6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int size = 4 * 1024;
char page[size];
void f()
{
  page[size + size] = 7; // undefined
}

void g(int* p)
{
  bool b = p; // narrows to true or false
  bool b2{ p != nullptr }; // explicit test against nullptr
  if (p) { // equivalent to p!=nullptr
    // ...
    return;
  }
  cout << "pass nullptr to |g|." << endl;
}

void intval()
{
  for (char c; cin >> c;)
    cout << "the value of '" << c << "' is " << int{ c } << '\n';
}

void digits()
{
  for (int i = 0; i != 10; ++i)
    cout << static_cast<char>('0' + i);
}

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "sizeof(int): " << sizeof(int) << endl;
  static_assert(4 <= sizeof(int), "sizeof(int) too small");
  // Access violation writing
  // f();

  bool b1 = 7; // 7!=0, so b becomes true
//  bool b2 {7}; // error : narrowing (§2.2.2, §10.5)
  int i1 = true; // i1 becomes 1
  int i2 {true}; // i2 becomes 1

  bool a = true;
  bool b = true;
  bool x = a + b; // a+b is 2, so x becomes true
  bool y = a || b; // a||b is 1, so y becomes true ("||" means "or")
  bool z = a - b; // a-b is 0, so z becomes false
  g(nullptr);
  intval();
  digits();

  char c = 255; // 255 is ‘‘all ones,’ ’ hexadecimal 0xFF
  int i = c;
 	return 0;
}

