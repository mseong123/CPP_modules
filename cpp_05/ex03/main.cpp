#include "Intern.hpp"

int	main(void) {
	Intern someRandomIntern;
	AForm* newform;
	newform = someRandomIntern.makeForm("rubbish form", "Bender");
	newform = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	delete newform;
	newform = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	delete newform;
	newform = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	delete newform;
	return (0);
}