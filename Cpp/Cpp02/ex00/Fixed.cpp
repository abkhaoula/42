#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& p) {
    std::cout << "Copy constructor called" << std::endl;
    value = p.getRawBits();
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& p) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = p.getRawBits();
    return *this;
}
int Fixed::getRawBits ( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}
void Fixed::setRawBits( int const raw ) {
    std::cout << "hummmmm" << std::endl;
    value = raw;
}