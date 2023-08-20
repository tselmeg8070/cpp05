#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form("Presidential Pardon Form", 145, 137), target_(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &form)
	: Form(form), target_(form.target_)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
		this->target_ = form.target_;
	return (*this);
}

const char *ShrubberyCreationForm::FileCreationError::what() const throw() {
	return ("Couldn't create file");
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	resFile;

	if (!this->getIsSigned())
		throw Form::GradeIsNotSignedException();
	else if (executor.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getGradeRequire())
		throw Form::GradeTooLowException();
	else
	{
		resFile.open(target_ + "_shrubbery");
		if (resFile.is_open())
		{
			resFile << "       _-_" << std::endl;
			resFile << "    /~~   ~~\\" << std::endl;
			resFile << " /~~         ~~\\" << std::endl;
			resFile << "{               }" << std::endl;
			resFile << " \\  _-     -_  /" << std::endl;
			resFile << "   ~  \\ //  ~" << std::endl;
			resFile << "_- -   | | _- _" << std::endl;
			resFile << "  _ -  | |   -_" << std::endl;
			resFile << "  _ -  | |   -_" << std::endl;
			resFile << "      // \\" << std::endl;
			resFile.close();
		}
		else
			throw ShrubberyCreationForm::FileCreationError();
	}
}
