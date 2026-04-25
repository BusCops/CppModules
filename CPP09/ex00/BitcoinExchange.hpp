#ifndef BITCOINEXCHANGER_HPP
#define BITCOINEXCHANGER_HPP

#include <cmath>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <sstream>
#include <time.h>

#define BTC_RELEASE_YEAR 2009
#define SECONDS_IN_DAY   86400

class BitcoinExchange
{
  private:
    std::map<int, double> data;
    std::map<int, double> input;
    std::string           dataFile;
    int                   currentYear;

  public:
    BitcoinExchange();
    BitcoinExchange(const std::string &file);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void buildData();
    void buildData(const std::string &file);

    int    parseDate(const std::string &date);
    double parseValue(const std::string &value);
    void
    parseLine(const std::string &line, const std::string &sep, bool parseMode);
};

#endif