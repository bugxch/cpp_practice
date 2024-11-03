
#ifndef CH2_01_H
#define CH2_01_H

// 说明函数模板的作用，如果传入函数模板的是自定义类，那么这个类要支持函数中的操作
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}


struct TestClass
{
    int v_{};
    TestClass() = default;

    TestClass(int v) : v_(v)
    {
    }
    bool operator>(const TestClass &t) const;
};
#endif