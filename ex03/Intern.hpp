#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	Intern(Intern &t);
	~Intern();
	Intern& operator=(const Intern &t);
	Form	*makeForm(const std::string &name, const std::string &target) const;
};

#endif
