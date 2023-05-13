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

LN10::LN10(long long numll)
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

    while (tmp >= 10)
    {
        tmp /= 10;
        bytesSize++;
    }
    bytes = new uint8_t[bytesSize];
    capacity = bytesSize;

    int j = 0;
    while (unumll > 0)
    {
        bytes[j] = unumll % 10;
        unumll /= 10;
        j++;
    }
    isNaN = false;
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

LN10::LN10(const LN10 &number, int first, int last)
{
    bytesSize = last - first + 1;
    capacity = bytesSize;
    isNegative = false;
    isNaN = number.isNaN;
    if (number.bytes)
    {
        bytes = new uint8_t[capacity];
        copy_n(number.bytes + first, bytesSize, bytes);
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
    if (number.isNaN || this->isNaN)
    {
        result.isNaN = true;
        return result;
    }
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
    if (number.isNaN || this->isNaN)
    {
        result.isNaN = true;
        return result;
    }
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
    if (this->isNaN)
        return string("NaN");
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
    for (int i = this->bytesSize - 1; i >= 0; i--)
    {
        if ((*this)[i] < number[i])
            return -1;
        if ((*this)[i] > number[i])
            return 1;
    }
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
    if (number.isNaN || this->isNaN)
    {
        result.isNaN = true;
        return result;
    }
    for (int i = 0; i < number.bytesSize; i++)
    {
        result = result + this->mult(number[i], i);
    }
    result.isNegative = !(this->isNegative == number.isNegative);
    return result;
}

// result is 10-base digit
// this->bytesSize = number.bytesSize || number.bytesSize + 1
uint8_t LN10::choice_division(const LN10 &number)
{
    uint8_t result = 0;
    LN10 tmp = number;
    while ((*this) >= tmp.mult(result + 1, (unsigned)0))
    {
        result++;
    }
    return result;
}

LN10 LN10::division(const LN10 &number)
{
    unsigned resultCapacity = this->bytesSize - number.bytesSize + 1;
    uint8_t *arr = new uint8_t[resultCapacity];
    unsigned resultSize = 0;
    unsigned appendix = 0;
    LN10 tmp = LN10(number.bytesSize);
    LN10 numberCopy = number;
    numberCopy.isNegative = false;
    LN10 thisCopy = LN10(*this);
    thisCopy.isNegative = false;
    unsigned prevBytesSize = thisCopy.bytesSize;
    for (int i = (int)this->bytesSize - 1; i >= (int)numberCopy.bytesSize - 1; i--)
    {
        tmp.bytes = thisCopy.bytes + i - numberCopy.bytesSize + 1;
        tmp.bytesSize = number.bytesSize + appendix;

        arr[resultSize] = tmp.choice_division(numberCopy);

        thisCopy = LN10(thisCopy - (LN10(arr[resultSize]) * numberCopy).mult(1, i - number.bytesSize + 1));
        if (arr[resultSize] == 0 || thisCopy.bytesSize == prevBytesSize)
        {
            appendix++;
        }
        else if (prevBytesSize - thisCopy.bytesSize != 1)
        {
            appendix = 0;
        }
        prevBytesSize = thisCopy.bytesSize;
        resultSize++;
    }
    tmp.bytes = nullptr;
    for (int i = resultSize; i < resultCapacity; i++)
        arr[i] = 0;
    int left = 0, right = resultSize - 1;
    uint8_t buf;
    while (left < right)
    {
        buf = arr[left];
        arr[left] = arr[right];
        arr[right] = buf;
        left++;
        right--;
    }

    LN10 result = LN10(resultCapacity);
    result.bytesSize = resultSize;
    result.bytes = arr;
    while (result.bytes[result.bytesSize - 1] == 0 && result.bytesSize > 1)
        result.bytesSize--;
    result.isNegative = !(this->isNegative == number.isNegative);

    return result;
}

LN10 LN10::operator/(const LN10 &number)
{
    if (LN10((long long)0) == number || number.isNaN || this->isNaN)
    {
        LN10 result;
        result.isNaN = true;
        return result;
    }
    return this->division(number);
}

LN10 LN10::mod(const LN10 &number)
{
    LN10 result = (*this) - (((*this) / number) * number);
    if (this->isNegative != number.isNegative)
    {
        return result + number;
    }
    return result;
}

LN10 LN10::operator%(const LN10 &number)
{
    if (LN10((long long)0) == number || number.isNaN || this->isNaN)
    {
        LN10 result;
        result.isNaN = true;
        return result;
    }
    return this->mod(number);
}

LN10 LN10::sqrt()
{
    LN10 mid = LN10((long long)0);

    if (this->isNegative)
    {
        mid.isNaN = true;
        return mid;
    }

    LN10 left = LN10((long long)0);
    LN10 right = LN10(*this);
    LN10 postmid;
    while (left < right)
    {
        cout << "left: " << left.to_string() << ", right: " << right.to_string() << endl;
        cout << "left + right = " << (left + right).to_string() << endl;
        mid = (left + right) / LN10((long long)2);
        cout << mid.to_string() << endl;
        postmid = mid + LN10((long long)1);
        if ((*this) == (postmid * postmid))
            return postmid;
        if ((*this) < (postmid * postmid) && (*this) >= mid * mid)
            break;
        if ((*this) < mid * mid)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    return mid;
}

LN10 LN10::operator~()
{
    return this->sqrt();
}

LN10 LN10::operator-()
{
    if (this->isNaN || (*this) == LN10((long long)0))
        return *this;
    LN10 result = *this;
    result.isNegative = !(this->isNegative);
    return result;
}