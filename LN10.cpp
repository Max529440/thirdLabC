#include "LN10.h"
#include <iostream>

LN10::LN10()
{
    capacity = 0;
    bytesSize = 0;
    isNegative = false;
    isNaN = false;
    bytes = nullptr;
}

LN10::LN10(uint8_t num)
{
    capacity = 3;
    bytesSize = 0;
    isNegative = false;
    isNaN = false;
    bytes = nullptr;
    bytes = new uint8_t[3];
    while (num > 0)
    {
        bytes[bytesSize] = num % 10;
        num /= 10;
        bytesSize++;
    }
}

LN10::LN10(unsigned capacity)
{
    this->capacity = capacity;
    isNegative = false;
    isNaN = false;
    bytesSize = 0;
    bytes = nullptr;
    bytes = new uint8_t[capacity];
}

LN10::LN10(const LN10 &number)
{
    bytesSize = number.bytesSize;
    capacity = number.bytesSize;
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

LN10::LN10(LN10 &&moved) : bytes(moved.bytes),
                           bytesSize(moved.bytesSize),
                           capacity(moved.bytesSize),
                           isNegative(moved.isNegative),
                           isNaN(moved.isNaN)
{
    moved.bytes = nullptr;
}

LN10 &LN10::operator=(LN10 &&moved)
{
    if (this != &moved)
    {
        if (bytes)
            delete[] bytes;
        bytesSize = moved.bytesSize;
        capacity = moved.capacity;
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

LN10 &LN10::operator=(const LN10 &number)
{
    if (this != &number)
    {
        if (bytes)
            delete[] bytes;
        bytesSize = number.bytesSize;
        capacity = number.bytesSize;
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

LN10 LN10::operator+(const LN10 &number)
{
    LN10 result;
    std::cout << this << " " << &number << std::endl;
    if (this->isNegative && number.isNegative)
    {
        result = this->add(number);
        result.isNegative = true;
    }
    else if (!(this->isNegative) && !(number.isNegative))
    {
        result = this->add(number);
        result.isNegative = false;
    }
    else
    {
        result = this->sub(number);
    }
    return result;
}

LN10 LN10::operator-(const LN10 &number)
{
    LN10 result;
    std::cout << this << " " << &number << std::endl;
    if (this->isNegative && !number.isNegative)
    {
        result = this->add(number);
        result.isNegative = true;
    }
    else if (!(this->isNegative) && number.isNegative)
    {
        result = this->add(number);
        result.isNegative = false;
    }
    else
    {
        result = this->sub(number);
    }
    return result;
}

LN10 LN10::add(const LN10 &number)
{
    LN10 result = LN10((unsigned)(std::max(this->bytesSize, number.bytesSize) + 1));
    result.isNaN = this->isNaN;
    unsigned next = 0;
    unsigned current;
    for (int i = 0; i < result.capacity; i++)
    {
        current = (*this)[i] + number[i] + next;
        next = current / 10;
        result.bytes[i] = current % 10;
    }
    result.bytesSize = result.capacity;
    while (result.bytes[result.bytesSize - 1] == 0 && result.bytesSize > 1)
        result.bytesSize--;
    return result;
}

uint8_t LN10::operator[](int index) const
{
    if (index < 0)
        throw NegativeIndexError("Index can not be negative");
    if (index < bytesSize)
        return bytes[index];
    return 0;
}

LN10::~LN10()
{
    if (bytes)
        delete[] bytes;
}

string LN10::to_string()
{
    string result = string("");
    for (int i = 0; i < this->bytesSize; i++)
        result += std::to_string(bytes[i]);
    result = string(result.rbegin(), result.rend());

    return result;
}

// substract from abs bigger
LN10 LN10::sub(const LN10 &number)
{
    LN10 result = LN10((unsigned)(std::max(this->bytesSize, number.bytesSize)));
    result.isNaN = this->isNaN;
    int sign = this->abscmp(number);
    unsigned next = 0;
    int current;
    for (int i = 0; i < result.capacity; i++)
    {
        current = sign * ((int)(*this)[i] - (int)number[i]) - (int)next;
        if (current < 0)
        {
            current += 10;
            next = 1;
        }
        else
        {
            next = 0;
        }
        result.bytes[i] = (uint8_t)current;
    }
    result.bytesSize = result.capacity;
    while (result.bytes[result.bytesSize - 1] == 0 && result.bytesSize > 1)
        result.bytesSize--;
    if (sign == -1 && !this->isNegative || sign == 1 && this->isNegative)
        result.isNegative = true;
    else
        result.isNegative = false;
    return result;
}

int LN10::abscmp(const LN10 &number)
{
    if (this->bytesSize < number.bytesSize)
        return -1;
    if (this->bytesSize > number.bytesSize)
        return 1;
    if ((*this)[this->bytesSize - 1] < number[number.bytesSize - 1])
        return -1;
    if ((*this)[this->bytesSize - 1] > number[number.bytesSize - 1])
        return 1;
    return 0;
}

int LN10::cmp(const LN10 &number)
{
    if (this->isNegative && number.isNegative)
    {
        if (this->abscmp(number) == -1)
            return 1;
        if (this->abscmp(number) == 1)
            return -1;
        return 0;
    }
    if (!this->isNegative && number.isNegative)
    {
        return 1;
    }
    if (this->isNegative && !number.isNegative)
    {
        return -1;
    }
    if (this->abscmp(number) == -1)
        return -1;
    if (this->abscmp(number) == 1)
        return 1;
    return 0;
}

bool LN10::operator<(const LN10 &number)
{
    return this->cmp(number) == -1;
}

bool LN10::operator>(const LN10 &number)
{
    return this->cmp(number) == 1;
}

bool LN10::operator<=(const LN10 &number)
{
    return this->cmp(number) <= 0;
}

bool LN10::operator>=(const LN10 &number)
{
    return this->cmp(number) >= 0;
}

bool LN10::operator==(const LN10 &number)
{
    return this->cmp(number) == 0;
}

bool LN10::operator!=(const LN10 &number)
{
    return this->cmp(number) != 0;
}

LN10 LN10::mult(uint8_t digit, unsigned shift)
{
    LN10 tmp = LN10(this->bytesSize + 1 + shift);
    tmp.isNegative = this->isNegative;
    tmp.isNaN = this->isNaN;
    uint8_t next = 0;
    uint8_t digitmult;
    for (int i = 0; i < shift; i++)
    {
        tmp.bytes[tmp.bytesSize] = 0;
        tmp.bytesSize++;
    }
    for (int i = 0; i < this->bytesSize + 1; i++)
    {
        digitmult = (*this)[i] * digit + next;
        tmp.bytes[tmp.bytesSize] = digitmult % 10;
        next = digitmult / 10;
        tmp.bytesSize++;
        if (tmp.bytesSize == tmp.capacity - 1 && next == 0)
            break;
    }
    LN10 result;
    if (tmp.bytesSize < tmp.capacity)
    {
        result.capacity = tmp.bytesSize;
        result.bytes = new uint8_t[result.capacity];
        copy_n(tmp.bytes, result.capacity, result.bytes);
        result.bytesSize = tmp.bytesSize;
        result.isNegative = tmp.isNegative;
    }
    else
    {
        result = std::move(tmp);
    }

    return result;
}

LN10 LN10::operator*(const LN10 &number)
{
    LN10 result = LN10((uint8_t)0);
    for (int i = 0; i < number.bytesSize; i++)
    {
        result = result + this->mult(number[i], i);
    }
    result.isNegative = !(this->isNegative == number.isNegative);
    return result;
}