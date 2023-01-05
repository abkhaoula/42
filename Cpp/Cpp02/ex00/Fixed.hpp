#include <iostream>

class Fixed {
    private:
        int value;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& p);
        ~Fixed();
        Fixed& operator=(const Fixed& p);
        int getRawBits ( void ) const;
        void setRawBits( int const raw );
};