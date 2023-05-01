#include <iostream>
#include <vector>
#include "LN.h"
using namespace std;

void test_const_char_pos_1();
void test_const_char_pos_2();
void test_const_char_neg_3();
void test_const_char_neg_4();

void test_string_view_pos_1();
void test_string_view_pos_2();

void test_long_long_pos_1();
void test_long_long_pos_2();
void test_long_long_default_3();

void test_copy_pos_1();
void test_copy_pos_2();

void test_move_pos_1();
void test_move_pos_2();

int main()
{
 test_move_pos_1();
 return 0;
}

// clang++ -std=c++17

// 2337036
void test_const_char_pos_1()
{
 const char *numstr = "23A90C";
 LN number = LN(numstr);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  cout << (unsigned)number.bytes[i] << endl;
 }
}

// 2337036
void test_string_view_pos_1()
{
 string numstr = string("23A90C");
 LN number = LN(numstr);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  cout << (unsigned)number.bytes[i] << endl;
 }
}

// 2337036
void test_const_char_pos_2()
{
 const char *numstr = "-23A90C";
 LN number = LN(numstr);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  cout << (unsigned)number.bytes[i] << endl;
 }
}

// 2337036
void test_string_view_pos_2()
{
 string numstr = string("-23A90C");
 LN number = LN(numstr);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  cout << (unsigned)number.bytes[i] << endl;
 }
}

// 2337036
void test_long_long_pos_1()
{
 long long numll = 2337036;
 LN number = LN(numll);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  if (i > 10)
   break;
  cout << (unsigned)number.bytes[i] << endl;
 }
}

void test_long_long_pos_2()
{
 long long numll = -2337036;
 LN number = LN(numll);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  if (i > 10)
   break;
  cout << (unsigned)number.bytes[i] << endl;
 }
}

void test_const_char_neg_3()
{
 const char *numstr = "--23A90C";
 LN number = LN(numstr);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  cout << (unsigned)number.bytes[i] << endl;
 }
}

void test_const_char_neg_4()
{
 const char *numstr = "23A90R";
 LN number = LN(numstr);
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  cout << (unsigned)number.bytes[i] << endl;
 }
}

void test_copy_pos_1()
{
 long long numll = -2337036;
 LN number = LN(numll);
 LN number_copy = LN(number);
 cout << "isNaN = " << number_copy.isNaN << endl;
 cout << "isNegative = " << number_copy.isNegative << endl;
 cout << "bytesSize = " << number_copy.bytesSize << endl;
 for (int i = 0; i < number_copy.bytesSize; i++)
 {
  cout << (unsigned)number_copy.bytes[i] << endl;
 }
}

void test_move_pos_1()
{
 long long numll = -2337036;
 LN number = LN(numll);
 LN number_moved{number};
 cout << "isNaN = " << number_moved.isNaN << endl;
 cout << "isNegative = " << number_moved.isNegative << endl;
 cout << "bytesSize = " << number_moved.bytesSize << endl;
 for (int i = 0; i < number_moved.bytesSize; i++)
 {
  cout << (unsigned)number_moved.bytes[i] << endl;
 }
}

void test_long_long_default_3()
{
 LN number;
 cout << "isNaN = " << number.isNaN << endl;
 cout << "isNegative = " << number.isNegative << endl;
 cout << "bytesSize = " << number.bytesSize << endl;
 for (int i = 0; i < number.bytesSize; i++)
 {
  if (i > 10)
   break;
  cout << (unsigned)number.bytes[i] << endl;
 }
}

void test_copy_pos_2()
{
 long long numll = -2337036;
 LN number = LN(numll);
 LN number_copy = number;
 cout << "isNaN = " << number_copy.isNaN << endl;
 cout << "isNegative = " << number_copy.isNegative << endl;
 cout << "bytesSize = " << number_copy.bytesSize << endl;
 for (int i = 0; i < number_copy.bytesSize; i++)
 {
  cout << (unsigned)number_copy.bytes[i] << endl;
 }
}

void test_move_pos_2()
{
 long long numll = -2337036;
 LN number = LN(numll);
 LN number_moved;
 number_moved = move(number);
 cout << "isNaN = " << number_moved.isNaN << endl;
 cout << "isNegative = " << number_moved.isNegative << endl;
 cout << "bytesSize = " << number_moved.bytesSize << endl;
 for (int i = 0; i < number_moved.bytesSize; i++)
 {
  cout << (unsigned)number_moved.bytes[i] << endl;
 }
}