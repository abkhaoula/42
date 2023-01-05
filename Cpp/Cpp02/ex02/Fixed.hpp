#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& p);
        Fixed(const int v);
        Fixed(const float v);
        ~Fixed();
        Fixed& operator=(const Fixed& p);
        bool operator>(const Fixed& p1);
        bool operator<(const Fixed& p1);
        bool operator>=(const Fixed& p1);
        bool operator<=(const Fixed& p1);
        bool operator==(const Fixed& p1);
        bool operator!=(const Fixed& p1);
        Fixed operator+(const Fixed& p1);
        Fixed operator-(const Fixed& p1);
        Fixed operator*(const Fixed& p1);
        Fixed operator/(const Fixed& p1);
        Fixed& operator++(); // Pre-increment
        Fixed operator++(int); // Post-increment
        Fixed& operator--(); // Pre
        Fixed operator--(int); // Post
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        int getRawBits ( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;//
        int toInt( void ) const;//
};

std::ostream& operator<<(std::ostream& out, const Fixed& v);