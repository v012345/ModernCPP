#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list)
    {
        // 从 C++11 起, 使用 auto 关键字进行类型推导
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
};
//从 C++ 20 起，auto 甚至能用于函数传参
int add(auto x, auto y)
{
    return x + y;
}
template <typename T, typename U>
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}
template <typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}
int main()
{
    auto i = 5; // 被推导为 int
    auto j = 6; // 被推导为 int
    std::cout << add(i, j) << std::endl;
    auto arr = new auto(10); // arr 被推导为 int *
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    // after c++11
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value)
    {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    // after c++14
    auto q = add3<double, int>(1.0, 2);
    std::cout << "q: " << q << std::endl;

    return 0;
}
