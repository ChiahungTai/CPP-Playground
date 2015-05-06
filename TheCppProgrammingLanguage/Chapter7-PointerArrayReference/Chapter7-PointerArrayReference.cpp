// Chapter7-PointerArrayReference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::move;

void f(int* pi)
{
  void* pv = pi; // ok: implicit conversion of int* to void*
//  *pv; //error : can¡¦t dereference void*
//  ++pv; //error : can¡¦t increment void* (the size of the object pointed to is unknown)
  int* pi2 = static_cast<int*>(pv); //explicit conversion back to int*
//  double* pd1 = pv; // error
//  double* pd2 = pi; // error
  double* pd3 = static_cast<double*>(pv); // unsafe (¡±11.5.2)
}

void f1(int n)
{
//  int v1[n]; // error : array size not a constant expression
  vector<int> v2(n); // OK: vector with n int elements
}

template<typename T>
int byte_diff(T* p, T* q)
{
  return reinterpret_cast<char*>(q)-reinterpret_cast<char*>(p);
}
void diff_test()
{
  int vi[10];
  short vs[10];
  cout << vi << ' ' << &vi[1] << ' ' << &vi[1]-&vi[0] << ' ' << byte_diff(&vi[0], &vi[1]) << '\n';
  cout << vs << ' ' << &vs[1] << ' ' << &vs[1]-&vs[0] << ' ' << byte_diff(&vs[0], &vs[1]) << '\n';
}


void print_m35(int m[3][5])
{
  for (int i = 0; i != 3; i++) {
    for (int j = 0; j != 5; j++)
      cout << m[i][j] << '\t';
    cout << '\n';
  }
}

void print_mi5(int m[][5], int dim1)
{
  for (int i = 0; i != dim1; i++) {
    for (int j = 0; j != 5; j++)
      cout << m[i][j] << '\t';
    cout << '\n';
  }
}

/* Compile error: error C2087: 'm' : missing subscript
void print_mij(int m[][], int dim1, int dim2) // doesn¡¦t behave as most people would think
{
for (int i = 0; i != dim1; i++) {
for (int j = 0; j != dim2; j++)
cout << m[i][j] << '\t'; // sur prise!
cout << '\n';
}
}
*/
// The correct one!
void print_mij(int* m, int dim1, int dim2)
{
  for (int i = 0; i != dim1; i++) {
    for (int j = 0; j != dim2; j++)
      cout << m[i*dim2 + j] << '\t'; // obscure
    cout << '\n';
  }
}

void f1(char* p)
{
  char s[] = "Gorm";
  const char* pc = s; // pointer to constant
  //pc[3] = 'g'; // error : pc points to constant
  pc = p; // OK
  char *const cp = s; // constant pointer
  cp[3] = 'a'; // OK
  //cp = p; // error : cp is constant
  const char *const cpc = s; // const pointer to const
  //cpc[3] = 'a'; // error : cpc points to constant
  //cpc = p; // error : cpc is constant
}

template<class K, class V>
class Map { // a simple map class
public:
  V& operator[](const K& v); // return the value corresponding to the key v
  pair<K, V>* begin() { return &elem[0]; }
  pair<K, V>* end() { return &elem[0] + elem.size(); }
private:
  vector<pair<K, V>> elem; // {key,value} pairs
};

template<class K, class V>
V& Map<K, V>::operator[](const K& k)
{
  for (auto& x : elem)
    if (k == x.first)
      return x.second;
  elem.push_back({ k, V{} }); // add pair at end (¡±4.4.2)
  return elem.back().second; // return the (default) value of the new element
}

string var{ "Cambridge" };
string f3(){ return ""; };

template<class T>
void swap(T& a, T& b) // "perfect swap" (almost)
{
  /*
  T tmp{ static_cast<T&&>(a) }; // the initialization may write to a
  a = static_cast<T&&>(b); // the assignment may write to b
  b = static_cast<T&&>(tmp); // the assignment may write to tmp
  */
  T tmp{ move(a) }; // move from a
  a = move(b); // move from b
  b = move(tmp); // move from tmp
}

char* ident(char* p) { return p; }

int _tmain(int argc, _TCHAR* argv[])
{
  int v1[] = { 1, 2, 3, 4 };
  char v2[] = { 'a', 'b', 'c', 0 };
//  char v3[2] = { 'a', 'b', 0 }; // error : too many initializers
  char v4[3] = { 'a', 'b', 0 }; // OK
  int v5[8] = { 1, 2, 3, 4 };
  // is equivalent to int v5[] = { 1, 2, 3, 4, 0, 0, 0, 0 };
//  int v6[8] = v5; // error : can¡¦t copy an array (cannot assign an int* to an array)
//  v6 = v5; // error : no array assignment
  cout << R"*(sizeof("Bohr") = )*" << sizeof("Bohr") <<endl;
  char* plato = "Plato"; // error, but accepted in pre-C++11-standard code
  //plato[4] = 'e'; // error : assignment to const
  char zeno[] = "Zeno"; // p is an array of 5 char
  zeno[0] = 'R'; // OK
  // the string is "quoted string"
  cout << R"("quoted string")" << endl;

  // "quoted string containing the usual terminator ("))"
  cout << R">>>("quoted string containing the usual terminator ("))")>>>" << endl;
    
  string counts{ R"(1
22
333)" };
  /*
  // Unicode string literals are not supported in MSVC
  "folder\\file" //implementation character set string
  R"(folder\file)" // implementation character raw set string
  u8"folder\\file" // UTF-8 string
  u8R"(folder\file)" // UTF-8 raw str ing
  u"folder\\file" // UTF-16 string
  uR"(folder\file)" //UTF-16 raw str ing
  U"folder\\file" // UTF-32 string
  UR"(folder\file)" //UTF-32 raw str ing
  u8"The official vowels in Danish are: a, e, i, o, u, \u00E6, \u00F8, \u00E5 and y."
  */
  cout << (3["Texas"] == "Texas"[3]) << ("Texas"[3] == 'a') << endl;
  cout << &"Texas" << endl;
  printf("&3[\"Texas\"] = %p\n", &3["Texas"]);
  printf("&\"Texas\"[3] = %p\n", &"Texas"[3]);
  cout << "Texas"[3] << endl;
  cout << "(v2[1] == 1[v2]) => " << (v2[1] == 1[v2]) << endl;
  diff_test();

  int v[3][5] = {
    { 0, 1, 2, 3, 4 }, { 10, 11, 12, 13, 14 }, { 20, 21, 22, 23, 24 }
  };

  print_m35(v);
  print_mi5(v, 3);
  print_mij(&v[0][0], 3, 5);
  print_mij(v[0], 3, 5);
//  print_mij(v, 3, 5); //type error
  
  const double& cdr{ 1 }; // OK
  double temp = double{ 1 }; // first create a temporar y with the right value
  const double& c_double_r{ temp }; // then use the temporar y as the initializer for cdr

  string& r1{ var }; // lvalue reference, bind r1 to var (an lvalue)
  //Looks like this is a MSVC compiler bug!
  string& r2{ f3() }; // lvalue reference, error : f() is an rvalue
//  string& r3{ "Princeton" }; // lvalue reference, error : cannot bind to temporar y
  string&& rr1{ f3() }; // rvalue reference, fine: bind rr1 to rvalue (a temporar y)
//  string&& rr2{ var }; // rvalue reference, error : var is an lvalue
  string&& rr3{ "Oxford" }; // rr3 refers to a temporar y holding "Oxford"
  const string& cr1{ "Harvard" }; // OK: make temporar y and bind to cr1

  string x, y;
//  string& a1[] = { x, y }; // error : array of references
  string* a2[] = { &x, &y }; // OK
//  vector<string&> s1 = { x, y }; // error : vector of references
  vector<string*> s2 = { &x, &y }; // OK

  char& r{ *ident(nullptr) }; // invalid code

  Map<string, int> buf;
  for (string s; std::cin >> s;) ++buf[s];
  for (const auto& x : buf)
    cout << x.first << ": " << x.second << '\n';
  return 0;
}
