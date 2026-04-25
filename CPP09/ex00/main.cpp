#include "BitcoinExchange.hpp"
#include <cstring>

int main()
{
    std::string date = "2012-1-99";
    tm          time;

	memset(&time,0,sizeof(time));
    if (!strptime(date.c_str(), "%Y-%m-%d", &time))
        std::cout << "failed" << std::endl;
    else
    {
		mktime(&time); // 🔥 normalization happens here
        std::cout << "year ->" << time.tm_year + 1900 << std::endl;
        std::cout << "month ->" << time.tm_mon + 1 << std::endl;
        std::cout << "day ->" << time.tm_mday << std::endl;
    }
}
