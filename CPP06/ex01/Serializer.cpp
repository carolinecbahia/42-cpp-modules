#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    if (this != &other)
    {
        // Copy the attributes here.
    }
    return *this;
}

Serializer::~Serializer()
{
}
