#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "You have entered " << argc
              << " arguments:"
              << "\n";

    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << "\n";

    return 0;
}
