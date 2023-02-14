#include "Array.hpp"

int main(void)
{
    Array<int> a(1337);
    
    try
    {
        a[42] = 1337;
        std::cout << a[42] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "index is out of range" << std::endl;
    }
    return (0);
}