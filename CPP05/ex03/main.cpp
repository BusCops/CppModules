#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat user("user", 5);
    Intern     randomIntern;
    AForm     *form;
    form = randomIntern.makeForm("presidential pardon", "randomTarget");
    if (form)
    {
        user.signForm(*form);
        user.executeForm(*form);
        delete (form);
    }
    form = randomIntern.makeForm("robotomy request", "randomTarget");
    if (form)
    {
        user.signForm(*form);
        user.executeForm(*form);
        delete (form);
    }
    form = randomIntern.makeForm("shrubbery creation", "randomTarget");
    if (form)
    {
        user.signForm(*form);
        user.executeForm(*form);
        delete (form);
    }
}