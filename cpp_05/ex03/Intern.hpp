#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern & src);
		Intern & operator=(Intern & src);
		AForm *makeShrubbery(std::string target);
		AForm *makePresidential(std::string target);
		AForm *makeRobotomy(std::string target);
		AForm *makeForm(std::string form, std::string target);
};

#endif