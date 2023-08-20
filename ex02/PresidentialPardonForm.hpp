#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		std::string	target_;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm &t);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &t);
		void	execute(const Bureaucrat& executor) const;
};

#endif
