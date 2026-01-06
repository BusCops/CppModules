#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat user("lmadani", 160);
        std::cout << user << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat user("mohamed", 0);
        std::cout << user << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat user("rachid", 90);
        std::cout << user << std::endl;
		Form formule("contract mirikan", 100, 80);
		user.signForm(formule);
		Form formule2("contrada sbalyon", 89, 70);
		user.signForm(formule2);
		user.incrementGrade();
		user.signForm(formule2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat user("mehdi", 1);
        user.incrementGrade();
        std::cout << user << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}