#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &)
{
}

Intern &Intern::operator=(const Intern &)
{
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::clonePres(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::cloneRobo(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::cloneShru(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    std::string Names[3] = {
        "robotomy request", "presidential pardon", "shrubbery creation"
    };

    AForm *(Intern::*func[3])(const std::string &) = {
        &Intern::cloneRobo, &Intern::clonePres, &Intern::cloneShru
    };

    for (int i = 0; i < 3; i++)
    {
        if (form == Names[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return (this->*func[i])(target);
        }
    }
    std::cout << "Intern didn't find any form with the name of " << form
              << std::endl;
    return NULL;
}
