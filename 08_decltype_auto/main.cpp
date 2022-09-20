#include <iostream>
#include <string>
std::string lookup1()
{
    return "1234567";
}
std::string &lookup2()
{
    return *(new std::string("987654"));
}
std::string look_up_a_string_1()
{
    return lookup1();
}
std::string &look_up_a_string_2()
{
    return lookup2();
}
// decltype(auto) 主要用于对转发函数或封装的返回类型进行推导
// 我们可以让编译器完成这一件烦人的参数转发
decltype(auto) look_up_a_string_1_1()
{
    return lookup1();
}
decltype(auto) look_up_a_string_2_1()
{
    return lookup2();
}
int main(int argc, char const *argv[])
{
    std::cout << lookup1() << std::endl;
    std::cout << lookup2() << std::endl;
    std::cout << look_up_a_string_1() << std::endl;
    std::cout << look_up_a_string_2() << std::endl;
    std::cout << look_up_a_string_1_1() << std::endl;
    std::cout << look_up_a_string_2_1() << std::endl;
    return 0;
}