#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);

    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;

    try
    {
        std::vector<int> v;
        v.reserve(5);
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        sp.addRange(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << '\n';
    }
    return 0;
}