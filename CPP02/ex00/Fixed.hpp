#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

private:
    int Number;
    const static int FractionalBits;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif