#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("Presidential Pardon Form", 25, 5), target_(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &form)
	: Form(form), target_(form.target_)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
		this->target_ = form.target_;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw Form::GradeIsNotSignedException();
	else if (executor.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getGradeRequire())
		throw Form::GradeTooLowException();
	else
		std::cerr << target_ << " has been pardoned by  Zaphod Beeblebrox." << std::endl;
}
