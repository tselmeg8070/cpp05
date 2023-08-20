#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include <string>
# include <fstream>
# include <stdexcept>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private:
		std::string	target_;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm &t);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &t);
		void	execute(const Bureaucrat& executor) const;

		class	FileCreationError : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
