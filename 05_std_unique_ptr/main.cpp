#include <iostream>
#include <memory>
#include <string>
struct Foo
{
    std::string name;
    Foo(std::string name) : name(name) { std::cout << name << " : Foo::Foo constructor" << std::endl; }
    ~Foo() { std::cout << name << " : Foo::~Foo destructor" << std::endl; }
    void foo() { std::cout << name << " : Foo::foo function" << std::endl; }
};

void f(const Foo &x)
{
    std::cout << x.name << " : f(const Foo&)" << std::endl;
}

int main()
{
    std::unique_ptr<Foo> p1(std::make_unique<Foo>("p1"));
    // p1 不空, 输出
    if (p1)
        p1->foo();
    {
        //既然是独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的 unique_ptr
        std::unique_ptr<Foo> p2(std::move(p1)); // !!!!!!!!!!!!!
        // p2 不空, 输出
        f(*p2);
        // p2 不空, 输出
        if (p2)
            p2->foo();
        // p1 为空, 无输出
        if (p1)
            p1->foo();

        //既然是独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的 unique_ptr
        p1 = std::move(p2);
        // p2 为空, 无输出
        if (p2)
            p2->foo();
        std::cout << "p2 被销毁" << std::endl;
    }
    // p1 不空, 输出
    if (p1)
        p1->foo();
    // Foo 的实例会在离开作用域时被销毁
}