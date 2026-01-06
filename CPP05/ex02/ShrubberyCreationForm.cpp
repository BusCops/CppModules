#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137),
      target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137),
      target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm("ShrubberyCreationForm", 145, 137)
{
    target = other.target;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
