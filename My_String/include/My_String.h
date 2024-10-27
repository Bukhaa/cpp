#pragma once
#include <iostream>


class My_String final
{
public:
    My_String(const char* str);
    ~My_String();
    My_String();
    My_String(const My_String& other);
    My_String(My_String&& other) noexcept;
    size_t Length()const;

    My_String& operator = (const My_String& other);
    My_String& operator=(My_String&& other)noexcept;
    friend std::istream& operator >> (std::istream& is, My_String& s);
    friend std::ostream& operator << (std::ostream& os, const My_String& s);
    bool operator == (const My_String& other)const;
    bool operator != (const My_String& other)const;
    char& operator [](int i);
    char operator [](int i)const;
    bool operator < (const My_String& other)const;
    bool operator > (const My_String& other)const;
    bool operator >= (const My_String& other)const;
    bool operator <= (const My_String& other)const;
    My_String operator + (const My_String& other)const;
    My_String operator +(const char* mass)const;
    friend My_String operator +(const char* mass, const My_String& other);
    My_String& operator++();
    My_String operator++(int);
    My_String& operator--();
    My_String operator --(int);
    My_String& operator +=(const My_String& other);

private:
    char* string;
    size_t len;
};

