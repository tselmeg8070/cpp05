#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <stdexcept>
# include <iostream>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(Bureaucrat &t);
	Bureaucrat& operator=(const Bureaucrat& t);
	~Bureaucrat();
	const std::string	&getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream & operator<<( std::ostream &o, Bureaucrat const &i);

#endif
