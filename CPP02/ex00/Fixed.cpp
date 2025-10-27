#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

// Constractor
Fixed::Fixed()
    : Number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constractor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        Number = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor  called!" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return Number;
}

// Setter
void Fixed::setRawBits(int const raw)
{
    std::cout << "SetRawBits member function called" << std::endl;
    Number = raw;
}
