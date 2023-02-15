#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {
    _vect.reserve(N);
}
void Span::addNumber(int n) {
    if (_vect.size() < _N)
        _vect.push_back(n);
    else
        throw std::exception();
}
int Span::shortestSpan() {
    if (_vect.size() < 2)
        throw std::exception();
    std::vector<int> v = _vect;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (unsigned int i = 1; i < v.size() - 1; i++)
    {
        if (v[i + 1] - v[i] < min)
            min = v[i + 1] - v[i];
    }
    return (min);
}
int Span::longestSpan() {
    if (_vect.size() < 2)
        throw std::exception();
    std::vector<int> v = _vect;
    std::sort(v.begin(), v.end());
    return (v[v.size() - 1] - v[0]);
}
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; it++)
    {
        addNumber(*it);
    }
}
Span & Span::operator=(const Span &copy) {
    _vect = copy._vect;
    _N = copy._N;
    return (*this);
}
Span::~Span() {}