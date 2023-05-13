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
void test_LN10_11();

void test_LN10_abscmp_1();
void test_LN10_abscmp_2();
void test_LN10_abscmp_3();

void test_LN10_cmp_1();
void test_LN10_cmp_2();
void test_LN10_cmp_3();
void test_LN10_cmp_4();
void test_LN10_cmp_5();
void test_LN10_cmp_6();
void test_LN10_cmp_7();
void test_LN10_cmp_8();
void test_LN10_cmp_9();
void test_LN10_cmp_10();

void test_LN10_mult_digit_1();
void test_LN10_mult_digit_2();
void test_LN10_mult_digit_3();
void test_LN10_mult_digit_4();

void test_LN10_mult_1();
void test_LN10_mult_2();

void test_LN10_slice_constructor_1();
void test_LN10_slice_constructor_2();
void test_LN10_slice_constructor_3();
void test_LN10_slice_constructor_4();

void test_LN10_choice_division_1();
void test_LN10_choice_division_2();
void test_LN10_choice_division_3();
void test_LN10_choice_division_4();

void test_LN10_long_long_1();
void test_LN10_long_long_2();

void test_LN10_division_1();
void test_LN10_division_2();
void test_LN10_division_3();
void test_LN10_division_4();
void test_LN10_division_5();
void test_LN10_division_6();
void test_LN10_division_7();
void test_LN10_division_8();

void test_LN10_mod_1();
void test_LN10_mod_2();
void test_LN10_mod_3();
void test_LN10_mod_4();
void test_LN10_mod_5();
void test_LN10_mod_6();

void test_LN10_sqrt_1();
void test_LN10_sqrt_2();
void test_LN10_sqrt_3();
void test_LN10_sqrt_4();
void test_LN10_sqrt_5();
void test_LN10_sqrt_6();
void test_LN10_sqrt_7();

int main()
{
    test_LN10_sqrt_7();
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

void test_LN10_11()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    LN10 num3 = num1 - num2;
    cout << "bytesSize: " << num3.bytesSize << endl;
    cout << "num3: " << num3.to_string() << endl;
    cout << "isNegative: " << num3.isNegative << endl;
}

void test_LN10_abscmp_1()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << num1.abscmp(num2) << endl;
}

void test_LN10_abscmp_2()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << num1.abscmp(num2) << endl;
}

void test_LN10_abscmp_3()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << num1.abscmp(num2) << endl;
}

void test_LN10_cmp_1()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_2()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_3()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_4()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = true;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_5()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = true;
    num2.isNegative = false;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_6()
{
    LN10 num1 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = true;
    num2.isNegative = true;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_7()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = true;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_8()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = true;
    num2.isNegative = false;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_9()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = true;
    num2.isNegative = true;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_cmp_10()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)230) + LN10((uint8_t)241);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    cout << "abscmp: " << num1.abscmp(num2) << endl;
    cout << "< " << (num1 < num2) << endl;
    cout << "> " << (num1 > num2) << endl;
    cout << "<= " << (num1 <= num2) << endl;
    cout << ">= " << (num1 >= num2) << endl;
    cout << "== " << (num1 == num2) << endl;
    cout << "!= " << (num1 != num2) << endl;
}

void test_LN10_mult_digit_1()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = false;

    LN10 res = num1.mult(2, 0);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_mult_digit_2()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = false;

    LN10 res = num1.mult(9, 0);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_mult_digit_3()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = false;

    LN10 res = num1.mult(9, 1);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_mult_digit_4()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = true;

    LN10 res = num1.mult(9, 3);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_mult_1()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    LN10 res = num1 * num2;
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_mult_2()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)43) + LN10((uint8_t)146);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = true;
    num2.isNegative = false;
    LN10 res = num1 * num2;
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_slice_constructor_1()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = true;

    LN10 res = LN10(num1, 0, 1);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_slice_constructor_2()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = true;

    LN10 res = LN10(num1, 1, 2);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_slice_constructor_3()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = true;

    LN10 res = LN10(num1, 1, 1);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_slice_constructor_4()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    num1.isNegative = true;

    LN10 res = LN10(num1, 0, 2);
    cout << "bytesSize: " << res.bytesSize << endl;
    cout << "capacity: " << res.capacity << endl;
    cout << "isNegative: " << res.isNegative << endl;
    cout << "res: " << res.to_string() << endl;
}

void test_LN10_choice_division_1()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)157);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    uint8_t res = num1.choice_division(num2);
    cout << "res: " << (unsigned)res << endl;
}

void test_LN10_choice_division_2()
{
    LN10 num1 = LN10((uint8_t)230) + LN10((uint8_t)195);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    uint8_t res = num1.choice_division(num2);
    cout << "res: " << (unsigned)res << endl;
}

void test_LN10_choice_division_3()
{
    LN10 num1 = LN10((uint8_t)10) + LN10((uint8_t)15);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    uint8_t res = num1.choice_division(num2);
    cout << "res: " << (unsigned)res << endl;
}

void test_LN10_choice_division_4()
{
    LN10 num1 = LN10((uint8_t)200) + LN10((uint8_t)200);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((uint8_t)50);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    num1.isNegative = false;
    num2.isNegative = false;
    uint8_t res = num1.choice_division(num2);
    cout << "res: " << (unsigned)res << endl;
}

void test_LN10_long_long_1()
{
    LN10 num = LN10((long long)123456);
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

void test_LN10_long_long_2()
{
    LN10 num = LN10((long long)-123456);
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 2071
void test_LN10_division_1()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)34);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 1235
void test_LN10_division_2()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 663
void test_LN10_division_3()
{
    LN10 num1 = LN10((long long)170414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)257);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 1
void test_LN10_division_4()
{
    LN10 num1 = LN10((long long)170414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)170414);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 0
void test_LN10_division_5()
{
    LN10 num1 = LN10((long long)170414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)270414);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// -663
void test_LN10_division_6()
{
    LN10 num1 = LN10((long long)170414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)-257);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "capacity: " << num2.capacity << endl;
    cout << "isNegative: " << num2.isNegative << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// -663
void test_LN10_division_7()
{
    LN10 num1 = LN10((long long)-170414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)257);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "capacity: " << num2.capacity << endl;
    cout << "isNegative: " << num2.isNegative << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

void test_LN10_division_8()
{
    LN10 num1 = LN10((long long)25);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)2);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "capacity: " << num2.capacity << endl;
    cout << "isNegative: " << num2.isNegative << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 / num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

// 0
void test_LN10_mod_1()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)34);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 % num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 19
void test_LN10_mod_2()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 % num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 70414
void test_LN10_mod_3()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)270414);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 % num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// >>> 70414 % -57
// -38
// >>> -70414 % 57
// 38
// >>> -70141 % -57
// -19

// -38
void test_LN10_mod_4()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)-57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 % num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// 38
void test_LN10_mod_5()
{
    LN10 num1 = LN10((long long)-70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 % num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

// -19
void test_LN10_mod_6()
{
    LN10 num1 = LN10((long long)-70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num2 = LN10((long long)-57);
    cout << "bytesSize: " << num2.bytesSize << endl;
    cout << "num2: " << num2.to_string() << endl;
    LN10 num = num1 % num2;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num1: " << num.to_string() << endl;
}

void test_LN10_sqrt_1()
{
    LN10 num1 = LN10((long long)25);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

void test_LN10_sqrt_2()
{
    LN10 num1 = LN10((long long)70414);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

void test_LN10_sqrt_3()
{
    LN10 num1 = LN10((long long)101);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

void test_LN10_sqrt_4()
{
    LN10 num1 = LN10((long long)0);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

void test_LN10_sqrt_5()
{
    LN10 num1 = LN10((long long)1);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

void test_LN10_sqrt_6()
{
    LN10 num1 = LN10((long long)2);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}

void test_LN10_sqrt_7()
{
    LN10 num1 = LN10((long long)-2);
    cout << "bytesSize: " << num1.bytesSize << endl;
    cout << "num1: " << num1.to_string() << endl;
    LN10 num = ~num1;
    cout << "capacity: " << num.capacity << endl;
    cout << "bytesSize: " << num.bytesSize << endl;
    cout << "isNegative: " << num.isNegative << endl;
    cout << "num: " << num.to_string() << endl;
}



/*
13823 / 26 = 531

13823
 26*5

823
26*3

43
26

17
============

34 * 2071 = 70414

70414 / 34 = 2071

70414
34*2

2414
 34*7

34
34

0

=======
res = 0

70414 / 34

res = 2

2414 / 34

res = 20

2414 / 34

res = 207

34

res 2071

0

========

70414 / 57 = 12

13414

2014


*/