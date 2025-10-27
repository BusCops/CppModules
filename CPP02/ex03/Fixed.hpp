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
    float toFloat(void) const;
    int toInt(void) const;
    // comparison operators
    bool operator==(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    // arithmetic operators
    float operator*(const Fixed &other);
    float operator+(const Fixed &other);
    float operator-(const Fixed &other);
    float operator/(const Fixed &other);
    // increment / decrement
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    //=======================================//
    static Fixed&  min(Fixed& first, Fixed& second);
    static Fixed&  max(Fixed& first, Fixed& second);
    static const Fixed&  min(const Fixed& first, const Fixed& second);
    static const Fixed&  max(const Fixed& first, const Fixed& second);

};

std::ostream &operator<<(std::ostream &cout, const Fixed &fixed);

#endif