#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm {
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
		std::string			_target;
	public:
		AForm(void);
		AForm(std::string name, int grade_sign, int grade_exec, std::string target);
		virtual ~AForm(void);
		AForm(AForm & src);
		AForm & operator=(AForm & src);
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException: public std::exception {
			public:
				const char* what() const throw();
		};
		const std::string getName() const;
		bool getSigned() const;
		const int getGradeSign() const;
		const int getGradeExec() const;
		std::string getTarget() const;
		void	beSigned(Bureaucrat & src);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & o, AForm & src);

#endif