#include <iostream>
#include <string>

void reference(std::string &str)
{
    std::cout << "left value" << std::endl;
}
void reference(std::string &&str)
{
    std::cout << "right value" << std::endl;
}

class A
{
public:
    int *pointer;
    A() : pointer(new int(1))
    {
        std::cout << "constructor" << pointer << std::endl;
    }
    A(A &a) : pointer(new int(*a.pointer))
    {
        std::cout << "copy" << pointer << std::endl;
    } // 无意义的对象拷贝
    A(A &&a) : pointer(a.pointer)
    {
        a.pointer = nullptr;
        std::cout << "move" << pointer << std::endl;
    }
    ~A()
    {
        std::cout << "unstructor" << pointer << std::endl;
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
    std::string lv1 = "string,"; // lv1 是一个左值
    // std::string&& r1 = lv1; // 非法, 右值引用不能引用左值
    std::string &&rv1 = std::move(lv1); // 合法, std::move可以将左值转移为右值
    std::cout << rv1 << std::endl;      // string,

    const std::string &lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    std::cout << lv2 << std::endl; // string,string,

    std::string &&rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
    rv2 += "Test";                 // 合法, 非常量引用能够修改临时变量
    std::cout << rv2 << std::endl; // string,string,string,Test

    reference(rv2); // 输出左值

    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;

    return 0;
}