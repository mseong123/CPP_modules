#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	std::cout << "ShrubberyCreationForm TEST" << std::endl;
	ShrubberyCreationForm shrubberyform("Hello");
	Bureaucrat bureauA("bureauA", 146);
	Bureaucrat bureauB("bureauB", 138);
	Bureaucrat bureauC("bureauC", 100);
	try {
		bureauA.signForm(shrubberyform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauB.executeForm(shrubberyform);
	}
	catch(AForm::FormNotSignedException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauB.signForm(shrubberyform);
		bureauB.executeForm(shrubberyform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauC.executeForm(shrubberyform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "RobotomyRequestForm TEST" << std::endl;
	RobotomyRequestForm robotomyform("Hello");
	Bureaucrat bureauD("bureauD", 73);
	Bureaucrat bureauE("bureauE", 46);
	Bureaucrat bureauF("bureauF", 22);
	try {
		bureauD.signForm(robotomyform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauE.executeForm(robotomyform);
	}
	catch(AForm::FormNotSignedException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauE.signForm(robotomyform);
		bureauE.executeForm(robotomyform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauF.executeForm(robotomyform);
		bureauF.executeForm(robotomyform);
		bureauF.executeForm(robotomyform);
		bureauF.executeForm(robotomyform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "PresidentialPardonForm TEST" << std::endl;
	PresidentialPardonForm presidentialpardonform("Hello");
	Bureaucrat bureauG("bureauG", 26);
	Bureaucrat bureauH("bureauH", 6);
	Bureaucrat bureauI("bureauI", 1);
	try {
		bureauG.signForm(presidentialpardonform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauH.executeForm(presidentialpardonform);
	}
	catch(AForm::FormNotSignedException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauH.signForm(presidentialpardonform);
		bureauH.executeForm(presidentialpardonform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		bureauI.executeForm(presidentialpardonform);
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "DESTROYING FORMS AND BUREAUCRATS" << std::endl;
	return (0);
}