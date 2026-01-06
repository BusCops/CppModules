#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
  private:
    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

  public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();

    const std::string &getName() const;
    bool               getIsSigned() const;
    int                getGradeToExecute() const;
    int                getGradeToSign() const;
    void               beSigned(const Bureaucrat &Bureaucrat);
    virtual void       execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &cout, const AForm &Form);

#endif