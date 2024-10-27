#define _CRT_SECURE_NO_WARNINGS
#include <stdexcept>
#include <cstring>
#include "My_String.h"


My_String::My_String()
{
    string = nullptr;
    len = 0;
}

My_String::My_String(const My_String& other)
{
    std::cout << "copy ctor" << std::endl;
    len = strlen(other.string);
    this->string = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        this->string[i] = other.string[i];
    }
    this->string[len] = '\0';
}

My_String::My_String(My_String&& other) noexcept
{
    std::cout << "move ctor" << std::endl;
    this->len = other.len;
    this->string = other.string;
    other.string = nullptr;
}

My_String::My_String(const char* str)
{
    len = strlen(str);
    this->string = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        this->string[i] = str[i];
    }
    this->string[len] = '\0';
}

My_String::~My_String()
{
    delete[] this->string;
}

My_String& My_String::operator=(const My_String& other)
{
    std::cout << "op =" << std::endl;
    if (this == &other)
        return *this;

    if (this->string != nullptr)
    {
        delete[] this->string;
    }

    len = strlen(other.string);
    this->string = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        this->string[i] = other.string[i];
    }
    this->string[len] = '\0';

    return *this;
}

My_String& My_String::operator=(My_String&& other)noexcept
{
    
    if (this == &other)
        return *this;

    if (this->string != nullptr)
    {
        delete[] this->string;
    }

    this->len = other.len;
    this->string = other.string;
    other.string = nullptr;
    return *this;
}

My_String My_String::operator+(const My_String& other)const
{
    My_String res_string(*this);
    res_string += other;
    return res_string;
}

My_String My_String::operator+(const char* mass)const
{
    My_String result_string;
    size_t len_1 = strlen(mass);
    size_t len_2 = this->len;
    result_string.len = len_1 + len_2;
    result_string.string = new char[len_1 + len_2 + 1];

    int i = 0, j = 0;
    for (; i < len_2; i++)
    {
        result_string.string[i] = this->string[i];
    }

    for (; j < len_1; j++, i++)
    {
        result_string.string[i] = mass[j];
    }

    result_string.string[len_1 + len_2] = '\0';
    return result_string;
}

My_String& My_String::operator++()
{
    for (size_t i = 0; i < strlen(string); ++i)
        string[i] = toupper(string[i]);
    return *this;
}

My_String My_String::operator++(int)
{
    My_String string_temp(*this);
    ++(*this);
    return string_temp;
}

My_String& My_String::operator--()
{
    for (size_t i = 0; i < strlen(string); ++i)
        string[i] = tolower(string[i]);
    return *this;
}

My_String My_String::operator--(int)
{
    My_String string_temp(*this);
    --(*this);
    return string_temp;
}

My_String& My_String::operator +=(const My_String& other)
{
    char* NewString = new char[strlen(string) + strlen(other.string) + 1];
    strcpy(NewString, string);
    strcat(NewString, other.string);
    delete[] string;
    string = NewString;
   
    return *this;
}

bool My_String::operator==(const My_String& other)const
{
    if (this->len != other.len)
        return false;

    for (int i = 0; i < this->len; i++)
    {
        if (this->string[i] != other.string[i])
            return false;
    }

    return true;
}

bool My_String::operator!=(const My_String& other)const
{
    return !(this->operator==(other));
}

char& My_String::operator[](int i)
{
    if (string == nullptr || i < 0 || i >= this->len)
        throw std::exception();

    return this->string[i];
}

char My_String::operator[](int i) const
{
    if (string == nullptr || i < 0 || i >= this->len)
        throw std::exception();
    return this->string[i];
}

bool My_String::operator<(const My_String& other)const
{
    return this->len < other.len;
}

bool My_String::operator>(const My_String& other)const
{
    return this->len > other.len;
}

bool My_String::operator>=(const My_String& other)const
{
    return !(len < other.len);
}

bool My_String::operator<=(const My_String& other)const
{
    return !(len > other.len);
}

size_t My_String::Length() const
{
    return len;
}

std::ostream& operator << (std::ostream& os, const My_String& s)
{
    os << s.string;
    return os;
}

std::istream& operator>>(std::istream& is, My_String& s)
{
    char* buf = new char[256];
    is.getline(buf, 256);
    s.len = strlen(buf);
    s.string = new char[s.len + 1];
    strcpy(s.string, buf);
    delete[] buf;
    return is;
}

My_String operator +(const char* mass, const My_String& other)
{
    My_String result_string;
    size_t len_1 = strlen(mass);
    size_t len_2 = strlen(other.string);
    result_string.len = len_1 + len_2;
    result_string.string = new char[len_1 + len_2 + 1];

    int i = 0, j = 0;
    for (; i < len_1; i++)
    {
        result_string.string[i] = mass[i];
    }

    for (; j < len_2; j++, i++)
    {
        result_string.string[i] = other.string[j];
    }

    result_string.string[len_1 + len_2] = '\0';

    return result_string;
}
