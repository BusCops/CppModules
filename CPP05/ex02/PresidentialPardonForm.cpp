#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5),
      target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5),
      target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other
)
    : AForm("PresidentialPardonForm", 25, 5)
{
    target = other.target;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	
}