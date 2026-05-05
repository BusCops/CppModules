#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>

class RPN
{
  private:
    std::stack<int> container;

  public:
    RPN();
    RPN &operator=(const RPN &other);
    ~RPN();

	void calculate(const std::string &numbers);
};

#endif