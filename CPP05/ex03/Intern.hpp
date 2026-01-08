#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
class AForm;

class Intern
{
  public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();
    AForm *clonePres(const std::string &target);
    AForm *cloneRobo(const std::string &target);
    AForm *cloneShru(const std::string &target);
    AForm *makeForm(const std::string &Form, const std::string &target);
};

#endif
