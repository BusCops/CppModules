#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed()
:Number(0)
{
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        Number = other.Number;
    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
    return Number;
}

void Fixed::setRawBits( int const raw )
{
    Number = raw;
}

Fixed::Fixed(const int number)
{
    Number = number << FractionalBits;
}

Fixed::Fixed(const float number)
{
    Number = roundf(number * (1 << FractionalBits));
}

float Fixed::toFloat( void ) const
{
    float f = Number;
    return (f / (1 << FractionalBits));
}

int Fixed::toInt( void ) const
{
    return (Number /  (1 << FractionalBits));
}

std::ostream& operator<<(std::ostream &cout, const Fixed &fixed)
{
    cout << fixed.toFloat();
    return cout;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    float x = Number;
    float y = other.Number;
    int fract = (1 << FractionalBits) * (1 << FractionalBits);
    return ((x * y) / fract);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    float x = Number;
    float y = other.Number;
    return  ((x + y) / (1 << FractionalBits));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    float x = Number;
    float y = other.Number;
    return  ((x - y) / (1 << FractionalBits));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    float x = Number;
    float y = other.Number;
    int fract = (1 << FractionalBits) / (1 << FractionalBits);
    return ((x / y) / fract);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (Number == other.Number);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (Number > other.Number);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (Number < other.Number);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (Number >= other.Number);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (Number <= other.Number);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (Number != other.Number);
}

Fixed& Fixed::operator++()
{
    Number++;
    return *this;
}

Fixed& Fixed::operator--()
{
    Number--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    Number++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    Number--;
    return tmp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    if (first.Number > second.Number)
        return second;
    else
        return first;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    if (first.Number > second.Number)
        return first;
    else
        return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
    if (first.Number > second.Number)
        return second;
    else
        return first;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
    if (first.Number > second.Number)
        return first;
    else
        return second;
}