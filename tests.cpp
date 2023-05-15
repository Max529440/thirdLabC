#include "tests.h"
#include <iostream>
#include <cassert>

void run_tests()
{
    test_LN10_1();
    test_LN10_2();
    test_LN10_2_1();
    test_LN10_3();
    test_LN10_4();
    test_LN10_5();
    test_LN10_6();
    test_LN10_7();
    test_LN10_8();
    test_LN10_9();
    test_LN10_10();
    test_LN10_11();
}

void describe(LN10 num)
{
    std::cout << "***describe***" << std::endl;
    std::cout << num.to_string() << std::endl;
    std::cout << num.capacity << std::endl;
    std::cout << num.bytesSize << std::endl;
    std::cout << num.isNaN << std::endl;
    std::cout << num.isNegative << std::endl;
    std::cout << "**************" << std::endl;
}

void ln_assert(LN10 expression, LN10 expected, std::string name_test)
{
    if (expression == expected)
    {
        std::cout << "test " << name_test << " \033[92mOK\033[0m" << std::endl;
    }
    else
    {
        std::cout << "test " << name_test << " \033[91mFAILED\033[0m" << std::endl;
    }
}

void test_LN10_1()
{
    LN10 num = LN10((uint8_t)230);
    ln_assert(num, 230_ln, "1");
}

void test_LN10_2()
{
    ln_assert(230_ln + 195_ln, 425_ln, "2");
}

void test_LN10_2_1()
{
    ln_assert(43_ln + 146_ln, 189_ln, "2_1");
}

void test_LN10_3()
{
    ln_assert(425_ln + 186_ln, 611_ln, "3");
}

void test_LN10_4()
{
    ln_assert(-425_ln + -186_ln, -611_ln, "4");
}

void test_LN10_5()
{
    ln_assert(425_ln + (-186_ln), 239_ln, "5");
}

void test_LN10_6()
{
    ln_assert(-425_ln + 186_ln, -239_ln, "6");
}

void test_LN10_7()
{
    ln_assert(425_ln - 186_ln, 239_ln, "7");
}

void test_LN10_8()
{
    ln_assert(-425_ln - -186_ln, -239_ln, "8");
}

void test_LN10_9()
{
    ln_assert(- -425_ln - 186_ln, 239_ln, "9");
}

void test_LN10_10()
{
    ln_assert(425_ln - -186_ln, 611_ln, "10");
}

void test_LN10_11()
{
    ln_assert(425_ln - 425_ln, 0_ln, "11");
}