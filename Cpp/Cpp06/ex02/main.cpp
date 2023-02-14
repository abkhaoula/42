#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate() {
    srand(time(0));
    int choice = rand() % 3;
    if (choice == 0) return new A;
    if (choice == 1) return new B;
    return new C;
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void    identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main(void)
{
    Base *p = generate();
    identify(p);
    identify(*p);
    return (0);
}