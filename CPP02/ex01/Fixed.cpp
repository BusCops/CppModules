#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed()
:Number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        Number = other.Number;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor  called!" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return Number;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "SetRawBits member function called" << std::endl;
    Number = raw;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    Number = number << FractionalBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
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