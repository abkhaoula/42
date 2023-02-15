#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _vect;
    public:
        Span();
        Span(unsigned int N);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        Span &operator=(const Span &copy);
        ~Span();
};

#endif