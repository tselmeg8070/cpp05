#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("Robotomy Request Form", 72, 45), target_(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &form)
	: Form(form), target_(form.target_)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
		this->target_ = form.target_;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	int	random;

	if (!this->getIsSigned())
		throw Form::GradeIsNotSignedException();
	else if (executor.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getGradeRequire())
		throw Form::GradeTooLowException();
	else
	{
		random = std::rand();
		std::cout << "Brrrrzzz.. " << std::endl;
		std::cout << "There is 1/2 chance" << std::endl;
		if (random % 2 == 0)
			std::cout << target_ << " has been robotimized.";
		else
			std::cerr << target_ << " failed to be robotimized.";
	}

}
