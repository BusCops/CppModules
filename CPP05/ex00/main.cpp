#include "Bureaucrat.hpp"

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