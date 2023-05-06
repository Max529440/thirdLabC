#include "LN10.h"
#include <iostream>

LN10::LN10() {
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
    capacity = number.capacity;
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
                           capacity(moved.capacity),
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
        capacity = number.capacity;
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
    unsigned next = 0;
    unsigned current;
    for (int i = 0; i < result.capacity; i++)
    {
        current = (*this)[i] + number[i] + next;
        next = current / 10;
        result.bytes[i] = current % 10;
    }
    result.bytesSize = result.capacity - 1;
    if (result.bytes[result.capacity - 1] != 0)
        result.bytesSize++;
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
    int sign = 1;
    if (this->bytesSize < result.capacity)
    {
        sign = -1;
    }
    else if (this->bytesSize == result.capacity)
    {
        if (this->bytesSize  == number.bytesSize)
        {
            if((*this)[this->bytesSize - 1] < number[number.bytesSize - 1])
            sign = -1;
        }
    }
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
    result.bytesSize = result.capacity - 1;
    if (result.bytes[result.capacity - 1] != 0)
        result.bytesSize++;
    if (sign == -1 && !this->isNegative || sign == 1 && this->isNegative)
        result.isNegative = true;
    else
        result.isNegative = false;
    return result;
}