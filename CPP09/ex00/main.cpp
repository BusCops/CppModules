#include "BitcoinExchange.hpp"

int main()
{
    try
    {
        BitcoinExchange test("data.csv");
    }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
