#include "Fixed.hpp"

int main( void ) {

Fixed const a( Fixed( 5.05f ) + Fixed( 2 ) );
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << c << std::endl;
std::cout << d << std::endl;
std::cout << std::boolalpha << (a == b) << std::endl;
std::cout << std::boolalpha << (a != b) << std::endl;
std::cout << std::boolalpha << (a >= b) << std::endl;
std::cout << std::boolalpha << (a <= b) << std::endl;
std::cout << std::boolalpha << (a > b) << std::endl;
std::cout << std::boolalpha << (a < b) << std::endl;

Fixed e;
std::cout << e << std::endl;
std::cout << ++e << std::endl;
std::cout << e++ << std::endl;
std::cout << e << std::endl;
std::cout << ++e << std::endl;
std::cout << --e << std::endl;

std::cout << Fixed::min(a, b) << std::endl;

Fixed f = Fixed::max(a, b);
std::cout << f << std::endl;
return 0;
}