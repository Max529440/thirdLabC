#include "LN.h"
#include <cstring>
#include <string_view>
#include <algorithm>
#include <iostream>

LN::LN(const char *numstr)
{
  unsigned sz = (unsigned)strlen(numstr);
  bytes = nullptr;
  if (sz == 0)
  {
    isNaN = true;
    return;
  }
  if (numstr[0] == '-')
  {
    bytesSize = (sz - 1) / 2 + unsigned((sz - 1) % 2);
  }
  else
    bytesSize = sz / 2 + unsigned(sz % 2);
  bytes = new uint8_t[bytesSize];
  if (numstr[0] == '-')
  {
    isNegative = true;
    parse_cstring(numstr + 1);
  }
  else
  {
    parse_cstring(numstr);
    isNegative = false;
  }
}

void LN::parse_cstring(const char *numstr)
{
  unsigned sz = (unsigned)strlen(numstr);
  int j = 0;
  for (int i = sz - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      bytes[j] = get_uint8_t_from_char(numstr[i]);
    }
    else
    {
      bytes[j] = get_uint8_t_from_char(numstr[i]) + get_uint8_t_from_char(numstr[i - 1]) * 16;
      i--;
    }
    j++;
    if (isNaN)
      break;
  }
}

uint8_t LN::get_uint8_t_from_char(char ch)
{
  uint8_t result;
  if (ch >= '0' && ch <= '9')
    result = ch - '0';
  else if (ch >= 'A' && ch <= 'F')
    result = ch - 'A' + 10;
  else
    isNaN = true;
  return result;
}

LN::LN(string_view numstr)
{
  unsigned sz = (unsigned)numstr.size();
  bytes = nullptr;
  if (sz == 0)
  {
    isNaN = true;
    return;
  }
  if (numstr.at(0) == '-')
  {
    isNegative = true;
    bytesSize = (sz - 1) / 2 + unsigned((sz - 1) % 2);
  }
  else
  {
    isNegative = false;
    bytesSize = sz / 2 + unsigned(sz % 2);
  }
  bytes = new uint8_t[bytesSize];
  parse_string_view(numstr);
}

void LN::parse_string_view(string_view numstr)
{
  int start = 0;
  if (numstr.at(0) == '-')
  {
    start++;
  }
  unsigned sz = (unsigned)numstr.size();
  int j = 0;
  for (int i = sz - 1; i >= start; i--)
  {
    if (i == start)
    {
      bytes[j] = get_uint8_t_from_char(numstr.at(i));
    }
    else
    {
      bytes[j] = get_uint8_t_from_char(numstr.at(i)) + get_uint8_t_from_char(numstr.at(i - 1)) * 16;
      i--;
    }
    j++;
    if (isNaN)
      break;
  }
}

LN::LN(long long numll)
{
  unsigned long long unumll;
  bytes = nullptr;
  if (numll < 0)
  {
    isNegative = true;
    unumll = -numll;
  }
  else
  {
    isNegative = false;
    unumll = numll;
  }
  bytesSize = 1;
  unsigned long long tmp = unumll;

  while (tmp > 256)
  {
    tmp /= 256;
    bytesSize++;
  }
  bytes = new uint8_t[bytesSize];

  int j = 0;
  while (unumll > 0)
  {
    bytes[j] = unumll % 256;
    unumll /= 256;
    j++;
  }
  isNaN = false;
}

LN::~LN()
{
  if (bytes)
    delete[] bytes;
}

LN::LN(const LN &number)
{
  bytesSize = number.bytesSize;
  isNegative = number.isNegative;
  isNaN = number.isNaN;
  if (number.bytes)
  {
    bytes = new uint8_t[bytesSize];
    copy_n(number.bytes, bytesSize, bytes);
  }
  else
    bytes = nullptr;
}

LN::LN(LN &&moved) : bytes(moved.bytes),
                     bytesSize(moved.bytesSize),
                     isNegative(moved.isNegative),
                     isNaN(moved.isNaN)
{
  moved.bytes = nullptr;
}

LN &LN::operator=(LN &&moved)
{
  if (this != &moved)
  {
    if (bytes)
      delete[] bytes;
    bytesSize = moved.bytesSize;
    isNegative = moved.isNegative;
    isNaN = moved.isNaN;
    if (moved.bytes)
    {
      bytes = moved.bytes;
    }
    else
      bytes = nullptr;
    moved.bytes = nullptr;
  }

  return *this;
}

LN &LN::operator=(const LN &number)
{
  if (this != &number)
  {
    if (bytes)
      delete[] bytes;
    bytesSize = number.bytesSize;
    isNegative = number.isNegative;
    isNaN = number.isNaN;
    if (number.bytes)
    {
      bytes = new uint8_t[bytesSize];
      copy_n(number.bytes, bytesSize, bytes);
    }
    else
      bytes = nullptr;
  }

  return *this;
}

string LN::to_string()
{
  return string("");
}

// Problem
// 35, 169, 12
// 12 + 169 * 256 + 35 * 256 ^ 2
// 12 = 12
// 169 * 256 = 43264
// 35 * 256 ^ 2 = 2293760

// 2, 2, 2, 9, 7, 6, 0
//       4, 3, 2, 6, 4
//                1, 2

// 2, 5, 6
// 2, 5, 6

// 6, 5, 5, 3, 6
//          3, 5

// 256 -> 10: +, *
// 10 -> 256: -, /
