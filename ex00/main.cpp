#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bureaucrat1("h", 1);
		Bureaucrat bureaucra2("l", 150);

		bureaucrat1.incrementGrade();
		bureaucra2.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
