#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static std::string nands[3] = {"-inf", "+inf", "nan"};
static std::string nanfs[3] = {"-inff", "+inff", "nanf"};

void printChar(char c)
{
    if (isprint(c))
        std::cout << "char: " << '\'' << c << '\'' << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

bool isChar(const std::string &str)
{
    if (str.size() == 1 && !isdigit(str[0]))
        return true;
    return false;
}

bool isInt(const std::string &str)
{
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
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

bool isFloat(const std::string &str)
{
    bool   dot = false;
    bool   f   = false;
    size_t i   = 0;

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
        else if (str[i] == 'f')
        {
            if (f || str.size() > i + 1)
                return false;
            f = true;
        }
        else if (!isdigit(str[i]))
            return false;
    }
    if (f && dot)
        return true;
    return false;
}

void convertChar(const std::string &str)
{
    char   c = str[0];
    int    i = static_cast<int>(c);
    double d = static_cast<double>(c);
    float  f = static_cast<float>(c);

    if (isprint(c))
        std::cout << "char: " << '\'' << c << '\'' << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
}

void convertInt(const std::string &str)
{
    double i;
    std::istringstream(str) >> i;

    if (i > INT_MAX || i < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (i > 127 || i < 0)
            std::cout << "char: impossible" << std::endl;
        else
        {
            char c = static_cast<char>(i);
            printChar(c);
        }
        int n = static_cast<int>(i);
        std::cout << "int: " << n << std::endl;
    }
    double d = static_cast<double>(i);
    float  f = static_cast<float>(i);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << 'f' << std::endl;
}

void convertDoubles(const std::string &str)
{
    double d;
    std::stringstream(str) >> d;

    if (d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min() || std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (d > 127 || d < 0)
            std::cout << "char: impossible" << std::endl;
        else
        {
            char c = static_cast<char>(d);
            printChar(c);
        }
        int i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
}

void convertFloat(const std::string &str)
{
    double f;
    std::stringstream(str) >> f;

    if (f > std::numeric_limits<int>::max() ||
        f < std::numeric_limits<int>::min() || std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (f > 127 || f < 0)
            std::cout << "char: impossible" << std::endl;
        else
        {
            char c = static_cast<char>(f);
            printChar(c);
        }
        int i = static_cast<int>(f);
        std::cout << "int: " << i << std::endl;
    }
    double d = f;
    float tmp = static_cast<float>(f);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << tmp << "f" << std::endl;
}

bool isNanD(const std::string &str)
{
    for (int i = 0; i < 3; i++)
    {
        if (str == nands[i])
            return true;
    }
    return false;
}

void printNanD(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "double: " << str << std::endl;
    std::cout << "float: " << str << 'f' << std::endl;
}

bool isNanF(const std::string &str)
{
    for (int i = 0; i < 3; i++)
    {
        if (str == nanfs[i])
            return true;
    }
    return false;
}

void printNanF(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
    std::cout << "float: " << str << std::endl;
}

void error()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    if (str.empty())
        error();
    else if (isChar(str))
        convertChar(str);
    else if (isInt(str))
        convertInt(str);
    else if (isDouble(str))
        convertDoubles(str);
    else if (isFloat(str))
        convertFloat(str);
    else if (isNanD(str))
        printNanD(str);
    else if (isNanF(str))
        printNanF(str);
    else
        error();
}