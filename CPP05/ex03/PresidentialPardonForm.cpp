#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5),
      target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("presidential pardon", 25, 5),
      target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other
)
    : AForm("presidential pardon", 25, 5)
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

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkRequirementExec(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}