#pragma once

#include <cstdint>
#include <string_view>
#include <string>
#include "LN.h"
using namespace std;

class NegativeIndexError
{
public:
 string message;
 NegativeIndexError(string msg) : message(msg){};
};

class LN10
{
public:
 uint8_t *bytes;
 unsigned bytesSize;
 unsigned capacity;
 bool isNegative;
 bool isNaN;

public:
 LN10();
 LN10(uint8_t num);
 LN10(unsigned capacity);
 LN10(const LN10 &number);
 LN10 &operator=(const LN10 &number);
 LN10(LN10 &&moved);
 LN10 &operator=(LN10 &&moved);
 LN10 operator+(const LN10 &number);
 LN10 operator-(const LN10 &number);
 uint8_t operator[](int index) const;
 string to_string();
 ~LN10();
 bool operator<(const LN10 &number);
 bool operator>(const LN10 &number);
 bool operator<=(const LN10 &number);
 bool operator>=(const LN10 &number);
 bool operator==(const LN10 &number);
 bool operator!=(const LN10 &number);
 LN10 operator*(const LN10 &number);

private:
 LN10 add(const LN10 &number);
 LN10 sub(const LN10 &number);
public:
 LN10 mult(uint8_t digit, unsigned shift);
 int abscmp(const LN10 &number);
 int cmp(const LN10 &number);

 // todo: all poerations with NaN return NaN
};