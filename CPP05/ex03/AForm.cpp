#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(""), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name),
      isSigned(false),
      gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

std::ostream &operator<<(std::ostream &cout, const AForm &Form)
{
    cout << "Form name " << Form.getName() << ", this form "
         << (Form.getIsSigned() ? "signed" : "not signed") << " grade to sign "
         << Form.getGradeToSign() << " grade to execute "
         << Form.getGradeToExecute() << ".";
    return cout;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void AForm::beSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

void AForm::checkRequirementExec(const Bureaucrat &Bureaucrat) const
{
    if (isSigned == false || Bureaucrat.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
}
