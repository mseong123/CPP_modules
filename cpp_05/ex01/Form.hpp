#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
	public:
		Form(void);
		Form(std::string name, int grade_sign, int grade_exec);
		~Form(void);
		Form(Form & src);
		Form & operator=(Form & src);
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		const std::string getName() const;
		bool getSigned() const;
		const int getGradeSign() const;
		const int getGradeExec() const;
		void beSigned(Bureaucrat & src);
};

std::ostream & operator<<(std::ostream & o, Form & src);

#endif