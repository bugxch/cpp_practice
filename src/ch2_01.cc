#include "ch2_01.h"


bool TestClass::operator>(const TestClass &t) const {
    return this->v_ > t.v_;
}