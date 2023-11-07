#include "Form.hpp"

int	main(void) {
	std::cout << "CONSTRUCTOR TEST" << std::endl;
	Form A;
	Form B("B", 40, 100);
	Form C = B;
	Form D;
	D = C;
	std::cout << A;
	std::cout << B;
	std::cout << C;
	std::cout << D;
	std::cout << std::endl;

	std::cout << "CONSTRUCTOR EXCEPTION TEST" << std::endl;
	try {
		std::cout << "Trying to initialise Form E with required grade sign: 151 and required grade execute: 150" << std::endl;
		Form E("E", 151, 150);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Trying to initialise Form F with required grade sign: 0 and required grade execute: 1" << std::endl;
		Form F("F", 0, 1);
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "FORM MEMBER FUNCTION BESIGNED TEST" << std::endl;
	Bureaucrat bureauA("bureauA", 41);
	Bureaucrat bureauB("bureauB", 8);
	Form G("G", 40, 100);
	std::cout << bureauA << " tries to sign " << G;
	try {
		bureauA.signForm(G);
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureauB << " tries to sign " << G;
	try {
		bureauB.signForm(G);
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << std::endl;

	std::cout << "DESTRUCTION OF FORMS AND BUREAUCRATS" <<std::endl;
	return (0);
}