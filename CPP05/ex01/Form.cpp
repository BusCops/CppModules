#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name(""), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name),
      isSigned(false),
      gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

std::ostream &operator<<(std::ostream &cout, const Form &Form)
{
    cout << "Form name " << Form.getName() << ", this form "
         << (Form.getIsSigned() ? "signed" : "not signed") << " grade to sign "
         << Form.getGradeToSign() << " grade to execute "
         << Form.getGradeToExecute() << ".";
    return cout;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Form::beSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}
