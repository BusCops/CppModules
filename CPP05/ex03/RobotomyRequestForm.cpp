#include "RobotomyRequestForm.hpp"
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy request", 72, 45),
      target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("robotomy request", 72, 45),
      target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("robotomy request", 72, 45)
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

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec);
    checkRequirementExec(executor);
    std::cout << "brr ! DRILLING NOISE ! brr ";
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully."
                  << std::endl;
    else
        std::cout << target << " the robotomy failed." << std::endl;
}