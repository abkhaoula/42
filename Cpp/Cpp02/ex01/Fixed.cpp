#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& p) {
    std::cout << "Copy constructor called" << std::endl;
    *this = p;
}

Fixed::Fixed(const int v) : value(v * (1 << fractional_bits)){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float v) : value(roundf(v * (1 << fractional_bits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits ( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits( int const raw ) {
    //hummmm cout??
    value = raw;
}

float Fixed::toFloat( void ) const {
    return (1.0 * value) / (1 << fractional_bits);
}

int Fixed::toInt( void ) const {
    return value >> fractional_bits;
}

Fixed& Fixed::operator=(const Fixed& p) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = p.value;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& v) {
    return out << v.toFloat();
}