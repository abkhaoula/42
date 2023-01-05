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
        int getRawBits ( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;//
        int toInt( void ) const;//
};

std::ostream& operator<<(std::ostream& out, const Fixed& v);