#include "BitcoinExchange.hpp"

int getCurrentYear()
{
    std::time_t now     = std::time(NULL);
    std::tm    *timePtr = std::localtime(&now);

    return timePtr->tm_year + 1900;
}

BitcoinExchange::BitcoinExchange() : dataFile()
{
    currentYear = getCurrentYear();
}

BitcoinExchange::BitcoinExchange(const std::string &file) : dataFile(file)
{
    currentYear = getCurrentYear();
    buildData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        currentYear = other.currentYear;
        data        = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool isInt(const std::string &str)
{
    size_t i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool isDouble(const std::string &str)
{
    size_t i   = 0;
    bool   dot = false;

    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (!isdigit(str[i]))
            return false;
    }
    if (dot)
        return true;
    return false;
}

int toInt(const std::string &n)
{
    if (!isInt(n))
        throw std::runtime_error("Error : bad input.");

    if (n[0] == '-')
        throw std::runtime_error("Error : not a positive number.");

    if (n[0] == '+')
        throw std::runtime_error("Error : bad input.");

    long num;

    for (size_t i = 0; i < n.size(); i++)
    {
        num = num * 10 + (n[i] - '0');
        if (num > INT_MAX)
            throw std::runtime_error("Error : bad input.");
    }
    return num;
}

double toDouble(const std::string &n)
{
    if (!isInt(n) && !isDouble(n))
        throw std::runtime_error("Error : bad Input.");

    if (n[0] == '-')
        throw std::runtime_error("Error : not a positive number.");

    if (n[0] == '+')
        throw std::runtime_error("Error : bad input.");

    double            d;
    std::stringstream s(n);

    s >> d;

    if (d > INT_MAX)
        throw std::runtime_error("Error : bad input.");

    return d;
}

int daysInMonth(int month, int year)
{
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        return 29;
    return days[month - 1];
}

int BitcoinExchange::parseDate(const std::string &date)
{
    if (date.size() != 10)
        throw std::runtime_error("Error : bad input.");

    int year = toInt(date.substr(0, 4));
    if (year < BTC_RELEASE_YEAR || year >> currentYear)
        throw std::runtime_error("Error : bad input.");

    int month = toInt(date.substr(5, 2));
    if (month > 12 || month < 0)
        throw std::runtime_error("Error : bad input.");

    int day = toInt(date.substr(8, 2));
    if (day > daysInMonth(month, year))
        throw std::runtime_error("Error : bad input.");

    std::tm t = {};
    t.tm_year = year - 1900;
    t.tm_mon  = month - 1;
    t.tm_mday = day;

    std::time_t seconds = std::mktime(&t);

    return seconds / (SECONDS_IN_DAY);
}

double BitcoinExchange::parseValue(const std::string &value)
{
    if (value.empty())
        throw std::runtime_error("Error : bad input.");

    double v = toDouble(value);

    return v;
}

void BitcoinExchange::parseLine(
    const std::string &line, const std::string &sep, bool parseMode
)
{
    size_t sepPos = line.find(sep);

    if (sepPos == std::string::npos)
        throw std::runtime_error("Error : bad input.");

    std::string date = line.substr(0, sepPos);
    int         key  = parseDate(date);

    if (data.find(key) != data.end() && parseMode) // on if data
        throw std::runtime_error("Error : duplicated date");

    std::string value = line.substr(sepPos + sep.size());
    double      v     = parseValue(value);

    if (v > 1000 && !parseMode) // off on input
        throw std::runtime_error("Error : bad input.");

    if (parseMode)
        data[key] = v;
    else
        input[key] = v;
}

void BitcoinExchange::buildData()
{
    if (dataFile.empty())
        throw std::runtime_error("Error : file name can't be empty.");

    std::fstream myFile(dataFile.c_str());

    if (!myFile.is_open())
        throw std::runtime_error("Error : opening file.");

    std::string line;

    while (getline(myFile, line))
    {
        parseLine(line, ",", true);
    }
}

void BitcoinExchange::buildData(const std::string &file)
{
    (void)file;
}
