#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	Form *form1 = 0;
	Form *form2 = 0;
	Form *form3 = 0;
	try {
		Bureaucrat bureaucrat("tselmeg", 2);
		Intern intern;
		form1 = intern.makeForm("shrubbery creation", "home");
		if (form1)
		{
			bureaucrat.signForm(*form1);
			bureaucrat.executeForm(*form1);
			delete form1;
			form1 = 0;
		}
		form2 = intern.makeForm("robotomy request", "home");
		if (form2)
		{
			bureaucrat.signForm(*form2);
			bureaucrat.executeForm(*form2);
			bureaucrat.executeForm(*form2);
			bureaucrat.executeForm(*form2);
			bureaucrat.executeForm(*form2);
			delete form2;
			form2 = 0;
		}
		form3 = intern.makeForm("presidential pardon", "home");
		if (form3)
		{
			bureaucrat.signForm(*form3);
			bureaucrat.executeForm(*form3);
			delete form3;
			form3 = 0;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	if (form1)
		delete form1;
	if (form2)
		delete form2;
	if (form3)
		delete form3;
	return (1);
}
