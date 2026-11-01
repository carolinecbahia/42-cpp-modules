#include "b.hpp"

b::b()
{
}

b::b(const b& other)
{
    *this = other;
}

b& b::operator=(const b& other)
{
    if (this != &other)
    {
        // Copy the attributes here.
    }
    return *this;
}

b::~b()
{
}
