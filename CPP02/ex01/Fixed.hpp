#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int Number;
    const static int FractionalBits;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int number);
    Fixed(const float number);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &cout, const Fixed &fixed);


#endif