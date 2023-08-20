#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class RobotomyRequestForm : public Form
{
	private:
		std::string	target_;
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm &t);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &t);
		void	execute(const Bureaucrat& executor) const;
};

#endif
