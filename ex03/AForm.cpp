#include "AForm.hpp"

Form::Form(const std::string &name, int gradeSigned, int gradeRequired)
	: name_(name), isSigned_(false), gradeSign_(gradeSigned), \
	gradeRequire_(gradeRequired)
{
	if (gradeSigned < 1)
		throw Form::GradeTooHighException();
	else if (gradeSigned > 150)
		throw Form::GradeTooLowException();
	if (gradeRequired < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequired > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{}

Form::Form(Form &t)
	:	name_(t.name_), isSigned_(t.isSigned_), gradeSign_(t.gradeSign_), \
		gradeRequire_(t.gradeRequire_)
{}

Form& Form::operator=(const Form &t)
{
	if (this != &t)
		isSigned_ = t.isSigned_;
	return (*this);
}

const std::string &Form::getName() const
{
	return (name_);
}

bool	Form::getIsSigned() const
{
	return (isSigned_);
}

int		Form::getGradeSign() const
{
	return (gradeSign_);
}

int		Form::getGradeRequire() const
{
	return (gradeRequire_);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeSign_)
		isSigned_ = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &t)
{
	os << t.getName() << ", is signed " << t.getIsSigned()
		<< ", grade to sign " << t.getGradeSign()
		<< ", grade to require " << t.getGradeRequire();
	return (os);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *Form::GradeIsNotSignedException::what(void) const throw()
{
	return ("Grade is not signed");
};
