#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const Fixed& p) {
    *this = p;
}

Fixed::Fixed(const int v) : value(v * (1 << fractional_bits)){
}

Fixed::Fixed(const float v) : value(roundf(v * (1 << fractional_bits))){
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& p) {
    value = p.value;
    return *this;
}

int Fixed::getRawBits ( void ) const {
    return (value);
}

void Fixed::setRawBits( int const raw ) {
    value = raw;
}

float Fixed::toFloat( void ) const {
    return (1.0 * value) / (1 << fractional_bits);
}

int Fixed::toInt( void ) const {
    return value >> fractional_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& v) {
    return out << v.toFloat();
}

bool Fixed::operator>(const Fixed& p1) {
    return (value > p1.value);
}

bool Fixed::operator<(const Fixed& p1) {
    return (value < p1.value);
}

bool Fixed::operator>=(const Fixed& p1) {
    return (value >= p1.value);
}

bool Fixed::operator<=(const Fixed& p1) {
    return (value <= p1.value);
}

bool Fixed::operator==(const Fixed& p1) {
    return (value == p1.value);
}

bool Fixed::operator!=(const Fixed& p1) {
    return (value != p1.value);
}

Fixed Fixed::operator+(const Fixed& p1) {
    return Fixed(toFloat() + p1.toFloat());
}

Fixed Fixed::operator-(const Fixed& p1) {
    return Fixed(toFloat() - p1.toFloat());
}

Fixed Fixed::operator*(const Fixed& p1) {
    return Fixed(toFloat() * p1.toFloat());
}

Fixed Fixed::operator/(const Fixed& p1) {
    return Fixed(toFloat() / p1.toFloat());
}


Fixed& Fixed::operator++()
{
    value += 1;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    value += 1;
    return(tmp);
}

Fixed& Fixed::operator--()
{
    value -= 1;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    value -= 1;
    return(tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a.value < b.value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.value < b.value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a.value > b.value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.value > b.value) ? a : b;
}