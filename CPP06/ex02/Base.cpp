#include "Base.hpp"

Base::Base()
{
}

Base::Base(const Base& other)
{
    *this = other;
}

Base& Base::operator=(const Base& other)
{
    if (this != &other)
    {
        // Copy the attributes here.
    }
    return *this;
}

Base::~Base()
{
}
