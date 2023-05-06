#include <iostream>
#include <vector>
#include "LN.h"
#include "LN10.h"
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

void test_LN10_1();
void test_LN10_2();
void test_LN10_2_1();
void test_LN10_3();
void test_LN10_4();
void test_LN10_5();
void test_LN10_6();
void test_LN10_7();
void test_LN10_8();
void test_LN10_9();
void test_LN10_10();

int main()
{
 test_LN10_10();
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

void test_LN10_1()
{
 LN10 num = LN10((uint8_t)230);
 cout << num.to_string() << endl;
}

void test_LN10_2()
{
 LN10 num1 = LN10((uint8_t)230);
 LN10 num2 = LN10((uint8_t)195);
 LN10 num3 = num1 + num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << num3.to_string() << endl;
}

void test_LN10_2_1()
{
 LN10 num1 = LN10((uint8_t)43);
 LN10 num2 = LN10((uint8_t)146);
 LN10 num3 = num1 + num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << num3.to_string() << endl;
}

void test_LN10_3()
{
 LN10 num11 = LN10((uint8_t)230);
 LN10 num12 = LN10((uint8_t)195);
 LN10 num1 = num11 + num12;
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num21 = LN10((uint8_t)43);
 LN10 num22 = LN10((uint8_t)146);
 LN10 num2 = num21 + num22;
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 LN10 num3 = num1 + num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_4()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = true;
 num2.isNegative = true;
 LN10 num3 = num1 + num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_5()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = false;
 num2.isNegative = true;
 LN10 num3 = num1 + num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_6()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = true;
 num2.isNegative = false;
 LN10 num3 = num1 + num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_7()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = false;
 num2.isNegative = false;
 LN10 num3 = num1 - num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_8()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = true;
 num2.isNegative = true;
 LN10 num3 = num1 - num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_9()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = true;
 num2.isNegative = false;
 LN10 num3 = num1 - num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_10()
{
 LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
 cout << "bytesSize: " << num1.bytesSize << endl;
 cout << "num1: " << num1.to_string() << endl;
 LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
 cout << "bytesSize: " << num2.bytesSize << endl;
 cout << "num2: " << num2.to_string() << endl;
 num1.isNegative = false;
 num2.isNegative = true;
 LN10 num3 = num1 - num2;
 cout << "bytesSize: " << num3.bytesSize << endl;
 cout << "num3: " << num3.to_string() << endl;
 cout << "isNegative: " << num3.isNegative << endl;
}