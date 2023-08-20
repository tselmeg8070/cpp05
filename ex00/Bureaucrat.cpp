#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

Bureaucrat::Bureaucrat(Bureaucrat &t) : name(t.name), grade(t.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& t)
{
	if (this != &t)
		grade = t.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::incrementGrade() {
	if (grade > 1)
		grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	if (grade < 150)
		grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &t)
{
	os << t.getName() << ", bureaucrat grade " << t.getGrade();
	return (os);
}
