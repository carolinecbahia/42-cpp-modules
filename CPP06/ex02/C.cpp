#include "C.hpp"

C::C()
{
}

C::C(const C& other)
{
    *this = other;
}

C& C::operator=(const C& other)
{
    if (this != &other)
    {
        // Copy the attributes here.
    }
    return *this;
}

C::~C()
{
}
