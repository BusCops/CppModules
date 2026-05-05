#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            BitcoinExchange test("data.csv");
            test.calculateBitcoinExchange(av[1]);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "how to use ->./btc \"input.txt\"" << std::endl;
}
