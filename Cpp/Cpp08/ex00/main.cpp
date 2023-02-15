#include "easyfind.hpp"


int main(void)
{
    std::vector<int> v;
    v.push_back(6);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    try
    {
        std::cout << easyfind(v, 3) << std::endl;
        std::cout << easyfind(v, 6) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Could not find element in list." << std::endl;
    }
    return (0);
}