#ifndef BITCOINEXCHANGER_HPP
#define BITCOINEXCHANGER_HPP

#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange
{
  private:
    std::map<std::string, int> data;
    std::string                file;

  public:
    BitcoinExchange();
	BitcoinExchange(const std::string &file);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

	void buildData();
    void buildData(const std::string &file);
};

#endif