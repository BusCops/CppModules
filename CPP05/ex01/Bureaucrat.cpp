#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &Bureaucrat)
{
    cout << Bureaucrat.getName() << ", bureaucrat grade "
         << Bureaucrat.getGrade() << ".";
    return cout;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Bureaucrat::signForm(Form &Form) const
{
    try
    {
        Form.beSigned(*this);
        std::cout << name << " signed " << Form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn’t sign " << Form.getName() << " because "
                  << e.what() << std::endl;
    }
}
