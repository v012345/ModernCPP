#include <iostream>
#include <vector>
#include <initializer_list>

class Foo
{
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }
};

class MagicFoo1
{
public:
    std::vector<int> vec;
    //初始化列表除了用在对象构造上，还能将其作为普通函数的形参
    void foo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }
};

int main()
{
    // before C++11
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    Foo foo2{1, 2};
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
    std::cout << "foo2:" << foo2.value_a << ", " << foo2.value_b << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};

    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
        std::cout << *it << std::endl;

    MagicFoo1 magicFoo1;
    magicFoo1.foo({6, 7, 8, 9});
    std::cout << "magicFoo1: ";
    for (std::vector<int>::iterator it = magicFoo1.vec.begin(); it != magicFoo1.vec.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}