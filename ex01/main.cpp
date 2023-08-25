#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bureaucrat1("h", 3);
		Bureaucrat bureaucrat2("l", 150);

		Form governor("Governor", 2, 1);
		bureaucrat1.signForm(governor);
		std::cout << governor << std::endl;
		Form accountant("Accountant", 20, 19);
		bureaucrat2.signForm(accountant);
		std::cout << accountant << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
