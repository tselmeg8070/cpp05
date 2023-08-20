#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(Intern &intern)
{}

Intern& Intern::operator=(const Intern &intern)
{
	return (*this);
}

Form*	Intern::makeForm(const std::string &name, const std::string &target) const
{
	static std::string	keys[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form*				forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
	int					index = -1;

	for (int i = 0; i < 3; i++)
		if (name == keys[i])
			index = i;
		else
			delete forms[i];
	if (index != -1)
		return (forms[index]);
	else
		std::cerr << "Requested form doesn't exist" << std::endl;
	return (0);
}
