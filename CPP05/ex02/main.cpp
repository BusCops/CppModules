#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat            user("user", 4);
        ShrubberyCreationForm form("home");
        user.signForm(form);
        user.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat             user("user", 4);
        PresidentialPardonForm form("oppo");
        user.signForm(form);
        user.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat            user("user", 140);
        ShrubberyCreationForm form("target");
        user.signForm(form);
        user.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat             user("user", 20);
        PresidentialPardonForm form("target");
        user.signForm(form);
        user.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat          user("user", 50);
        RobotomyRequestForm form("target");
        user.signForm(form);
        user.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        try
        {
            Bureaucrat          user("user", 4);
            RobotomyRequestForm form("robot");
            user.signForm(form);
            user.executeForm(form);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
