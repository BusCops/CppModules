#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45),
      target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45),
      target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("RobotomyRequestForm", 72, 45)
{
    target = other.target;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}