#pragma once

#include <cstdint>
#include <string_view>
using namespace std;

class LN
{
public:
 uint8_t *bytes;
 unsigned bytesSize;
 bool isNegative;
 bool isNaN;

public:
 LN(const char *numstr);
 LN(string_view numstr);
 LN(long long numll = 0);
 LN(const LN &number);
 LN &operator=(const LN &number);
 LN(LN &&moved);
 LN &operator=(LN &&moved);
 ~LN();

private:
 void parse_cstring(const char *numstr);
 void parse_string_view(string_view numstr);
 uint8_t get_uint8_t_from_char(char ch);
};
