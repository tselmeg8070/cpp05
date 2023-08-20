#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try {
		Bureaucrat bureaucrat("tselmeg", 2);
		ShrubberyCreationForm form1("Shrubbery");
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		RobotomyRequestForm form2("Robotomy");
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		PresidentialPardonForm form3("President");
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (1);
}
