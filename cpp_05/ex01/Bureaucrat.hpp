#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat & src);
		Bureaucrat & operator=(Bureaucrat & src);
		std::string const getName() const;
		int	getGrade() const;
		void	incremGrade();
		void	decremGrade();
		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		void	signForm(Form & src);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & src);

#endif