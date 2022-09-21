#include <iostream>
#include <thread>

int main()
{
    std::thread t([]()
                  {
        std::cout << "hello world." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        std::cout << "hello world." << std::endl; });
    t.join();
    return 0;
}