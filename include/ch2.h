#ifndef CH2_H
#define CH2_H

#include <iostream>
using namespace std;

template <typename T>
T sub_fun(T a, T b)
{
    return a - b;
}

// 类模板的定义
template <typename T>
class MyVector
{
public:
    using myiterator = T *;
    static void mystaticfunc()
    {
        cout << "mystaticfunc ()" << endl;
    }

public:
    // 列表初始化默认构造函数
    MyVector() : data_(nullptr), size_(0)
    {
    }
    // 重载赋值运算符
    MyVector &operator=(const MyVector &rhs)
    {
        cout << "operator=()" << endl;
        if (this != &rhs)
        {
            delete[] data_;
            data_ = new T[rhs.size_];
            size_ = rhs.size_;
            for (int i = 0; i < size_; ++i)
            {
                data_[i] = rhs.data_[i];
            }
        }
        return *this;
    }
    void myfunc()
    {
        cout << "myfunc()" << endl;
    }
    myiterator mybegin()
    {
        return data_;
    }
    myiterator myend()
    {
        return data_ + size_;
    }

private:
    T *data_;
    size_t size_;
};

#endif