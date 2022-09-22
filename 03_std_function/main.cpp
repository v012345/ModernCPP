#include <iostream>
#include <functional>

using foo = void(int); // 定义函数类型, using 的使用见上一节中的别名语法
void functional(foo f)
{         // 参数列表中定义的函数类型 foo 被视为退化后的函数指针类型 foo*
    f(1); // 通过函数指针调用函数
}

int bar(int para)
{
    return para;
}

int main()
{
    auto f = [](int value)
    {
        std::cout << value << std::endl;
    };
    functional(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
    f(1);          // lambda 表达式调用

    // std::function 包装了一个返回值为 int, 参数为 int 的函数
    std::function<int(int)> func = bar;

    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int
    {
        return 1 + value + important;
    };
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;

    return 0;
}