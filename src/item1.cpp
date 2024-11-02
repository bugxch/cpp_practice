#include "item1.h"
#include <iostream>
constexpr float pi = 3.1415f;

float Item1::GetArea() const
{
    return pi * price_ * price_;
}