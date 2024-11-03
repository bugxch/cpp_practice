#ifndef CH2_02_H
#define CH2_02_H

#include <iostream>
// 模板的泛化与特化，下面的类是模板的泛化版本
template <typename T, typename U>
struct TC
{
    // 这是泛化版本的静态成员
    static int m_stc;
    TC()
    {
        std::cout << "TC泛化版本构造函数" << std::endl;
    }
    void functtest1()
    {
        std::cout << "TC泛化版本functtest1" << std::endl;
    }
};


// 泛化版本中的静态成员，这个定义只能放在h文件中
template <typename T, typename V>
int TC<T, V>::m_stc = 10;

template <>
int TC<int, double>::m_stc = 20;

// 下面的全特化之后的类
template <> // 这一行不可或缺，否则会报错
struct TC<int, int>
{
    TC();
    void functtest1();
    // 新增全特化版本的函数
    void functtest2();
};

// Attention: 如果已经全特化了<int, int>类型，就不能再对其中的静态成员进行全特化了，下面的代码会报错
// template <>
// int TC<int, int>::m_stc = 30;

TC<int, int>::TC()
{
    std::cout << "TC全特化版本构造函数" << std::endl;
}

// This function is a part of the fully specialized version of the TC<int, int> class.
// It outputs a message indicating that functtest2 is called for the fully specialized version.
void TC<int, int>::functtest2()
{
    std::cout << "TC全特化版本functtest2" << std::endl;
}

void TC<int, int>::functtest1()
{
    std::cout << "TC全特化版本functtest1" << std::endl;
}

// 下面是泛化版本中的全特化版本的普通成员函数，泛化一个<float, int>的class，那么它的functest1()就会使用下面的版本
template <> // 这一行不可或缺，否则会报错
void TC<float, int>::functtest1()
{
    std::cout << "TC全特化版本普通成员函数的functtest1全特化版本" << std::endl;
}


#endif