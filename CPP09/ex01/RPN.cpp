#include "RPN.hpp"

static char operators[4] = {'+', '-', '*', '/'};

RPN::RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        container = other.container;
    }
    return *this;
}

RPN::~RPN()
{
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int sub(int num1, int num2)
{
    return num1 - num2;
}

int mult(int num1, int num2)
{
    return num1 * num2;
}

int div(int num1, int num2)
{
    return num1 / num2;
}

int executeOperation(char op, int num1, int num2)
{
    static int (*calculate_function[4])(int, int) = {add, sub, mult, div};

    int i = 0;

    for (; i < 4; i++)
    {
        if (operators[i] == op)
            break;
    }
    return calculate_function[i](num1, num2);
}

void RPN::calculate(const std::string &numbers)
{
    if (numbers.empty())
        throw std::runtime_error("Error : empty argument.");
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (isdigit(numbers[i]))
            container.push(numbers[i] - '0');
		else if (isOperator(numbers[i]))
        {
            if (container.size() < 2)
                throw std::runtime_error(
                    "Error : at least 2 numbers befor an operator."
                );
            int num2 = container.top();
            container.pop();
            int num1 = container.top();
            container.pop();
            int resault  = executeOperation(numbers[i], num1, num2);
			container.push(resault);
        }
        else
            throw std::runtime_error("Error : bad input.");
        if (i + 1 < numbers.size() && numbers[i + 1] != ' ')
            throw std::runtime_error("Error : bad input.");
        i++;
    }
	if (container.size() > 1)
		throw std::runtime_error("Error : bad input.");
	std::cout << "result : " << container.top() << std::endl;
}
