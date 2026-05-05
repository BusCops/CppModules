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
        throw std::invalid_argument("Error : bad input.");

    if (n[0] == '-')
        throw std::runtime_error("Error : not a positive number.");

    if (n[0] == '+')
        throw std::invalid_argument("Error : bad input.");

    long num = 0;

    for (size_t i = 0; i < n.size(); i++)
    {
        num = num * 10 + (n[i] - '0');
        if (num > INT_MAX)
            throw std::runtime_error("Error : too large a number.");
    }
    return num;
}

double toDouble(const std::string &n)
{
    if (!isInt(n) && !isDouble(n))
        throw std::invalid_argument("Error : bad Input.");

    if (n[0] == '-')
        throw std::runtime_error("Error : not a positive number.");

    if (n[0] == '+')
        throw std::invalid_argument("Error : bad input.");

    double            d;
    std::stringstream s(n);

    s >> d;

    if (d > INT_MAX)
        throw std::runtime_error("Error : too large a number.");

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
        throw std::invalid_argument("Error : bad input.");

    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error : bad input.");

    int year = toInt(date.substr(0, 4));
    if (year < BTC_RELEASE_YEAR || year > currentYear)
        throw std::invalid_argument("Error : bad input.");

    int month = toInt(date.substr(5, 2));
    if (month > 12 || month < 0)
        throw std::invalid_argument("Error : bad input.");

    int day = toInt(date.substr(8, 2));
    if (day > daysInMonth(month, year))
        throw std::invalid_argument("Error : bad input.");

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
        throw std::invalid_argument("Error : bad input.");

    double v = toDouble(value);

    return v;
}

void BitcoinExchange::parseDataLine(
    const std::string &line, const std::string &sep
)
{
    size_t sepPos = line.find(sep);

    if (sepPos == std::string::npos)
        throw std::invalid_argument("Error : bad input.");

    std::string date = line.substr(0, sepPos);
    int         key  = parseDate(date);

    if (data.find(key) != data.end())
        throw std::runtime_error("Error : duplicated date");

    std::string value = line.substr(sepPos + sep.size());
    double      v     = parseValue(value);

    data[key] = v;
}

void BitcoinExchange::buildData()
{
    if (dataFile.empty())
        throw std::runtime_error("Error : file name can't be empty.");

    std::fstream myFile(dataFile.c_str());

    if (!myFile.is_open())
        throw std::runtime_error("Error : opening file.");

    std::string line;

    getline(myFile, line);
    if (line != "date,exchange_rate")
        throw std::invalid_argument("Error : bad input.");

    while (getline(myFile, line))
    {
        parseDataLine(line, ",");
    }
}

void BitcoinExchange::buildData(const std::string &file)
{
    if (file.empty())
        throw std::runtime_error("Error : file name can't be empty.");

    std::fstream myFile(file.c_str());

    if (!myFile.is_open())
        throw std::runtime_error("Error : opening file.");

    std::string line;

    getline(myFile, line);
    if (line != "date,exchange_rate")
        throw std::invalid_argument("Error : bad input.");

    if (!data.empty())
        data.clear();

    while (getline(myFile, line))
    {
        parseDataLine(line, ",");
    }
}

void BitcoinExchange::calculateExchange(int days, double value)
{
    if (days < data.begin()->first)
        throw std::runtime_error("Error : no data for this date.");

    std::map<int, double>::iterator it = data.lower_bound(days);
    if (it == data.end())
        throw std::runtime_error("Error :  no data for this date.");

    if (it != data.begin() && it->first != days)
        it--;
    std::time_t seconds = days * SECONDS_IN_DAY;
    std::tm    *tm      = std::localtime(&seconds);
    char        buffer[11];

    std::sprintf(
        buffer, "%04d-%02d-%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday
    );

    std::cout << buffer << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::processeInput(
    const std::string &line, const std::string &sep
)
{
    size_t sepPos = line.find(sep);

    if (sepPos == std::string::npos)
        throw std::invalid_argument("Error : bad input.");

    std::string date = line.substr(0, sepPos);
    int         d    = parseDate(date);
    (void)d;
    std::string value = line.substr(sepPos + sep.size());
    double      v     = parseValue(value);

    if (v > 1000)
        throw std::runtime_error("Error : too large a number.");

    calculateExchange(d, v);
}

void BitcoinExchange::calculateBitcoinExchange(const std::string file)
{
    if (file.empty())
        throw std::runtime_error("Error : file name can't be empty.");

    std::fstream myFile(file.c_str());

    if (!myFile.is_open())
        throw std::runtime_error("Error : opening file.");

    std::string line;

    getline(myFile, line);
    if (line != "date | value")
        throw std::invalid_argument("Error : bad input.");

    while (getline(myFile, line))
    {
        try
        {
            processeInput(line, " | ");
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << " => " << line << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}