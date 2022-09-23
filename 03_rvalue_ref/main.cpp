#include <iostream>
class A
{
public:
    int *pointer;
    A() : pointer(new int(1))
    {
        std::cout << "构造" << pointer << std::endl;
    }
    A(A &a) : pointer(new int(*a.pointer))
    {
        std::cout << "拷贝" << pointer << std::endl;
    } // 无意义的对象拷贝
    A(A &&a) : pointer(a.pointer)
    {
        a.pointer = nullptr; //将亡值的指针被设置为 nullptr，防止了这块内存区域被销毁。
        std::cout << "移动" << pointer << std::endl;
    }
    ~A()
    {
        std::cout << "析构" << pointer << std::endl;
        delete pointer;
    }
};
// 防止编译器优化
A return_rvalue(bool test)
{
    A a, b;
    if (test)
        return a; // 等价于 static_cast<A&&>(a);
    else
        return b; // 等价于 static_cast<A&&>(b);
}
int main()
{
#if defined(_WIN64) || defined(_WIN32) || defined(__CYGWIN__)
    system("chcp 65001");
#endif
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;
    system("pause");
    return 0;
}