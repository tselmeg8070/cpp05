#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bureaucrat1("High", 0);
		Bureaucrat bureaucra2("Low", 150);

		bureaucrat1.incrementGrade();
		bureaucra2.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
