#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <string>
# include <stdexcept>
# include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	name_;
		bool				isSigned_;
		const int			gradeSign_;
		const int			gradeRequire_;
	public:
		Form(const std::string &name, int gradeSigned, int gradeRequired);
		~Form();
		Form(Form& t);
		Form& operator=(const Form& t);

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeSign() const;
		int					getGradeRequire() const;
		void				beSigned(const Bureaucrat &t);

		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<( std::ostream &o, Form const &i);

#endif
