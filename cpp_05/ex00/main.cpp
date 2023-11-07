#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "CONSTRUCTOR TEST" << std::endl;
	Bureaucrat A;
	Bureaucrat B("B", 130);
	Bureaucrat C(B);
	Bureaucrat D = C;
	Bureaucrat E;
	E = D;
	std::cout << A;
	std::cout << B;
	std::cout << C;
	std::cout << D;
	std::cout << E;
	std::cout << std::endl;

	std::cout << "CONSTRUCTOR EXCEPTION TEST" << std::endl;
	try {
		std::cout << "Trying to initialise Bureaucrat F with grade of 151" << std::endl;
		Bureaucrat F("F", 151);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Trying to initialise Bureaucrat G with grade of 0" << std::endl;
		Bureaucrat G("G", 0);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "MEMBER FUNCTION INCREMENT/DECREMENT TEST" << std::endl;
	std::cout << "Initialise Bureaucrat H with grade of 1" << std::endl;
	Bureaucrat H("H", 1);
	std::cout << "Initialise Bureaucrat I with grade of 150" << std::endl;
	Bureaucrat I("I", 150);
	try {
		H.decremGrade();
		std::cout << H;
		H.incremGrade();
		std::cout << H;
		std::cout << "Trying to increment grade beyond limit of 1" << std::endl;
		H.incremGrade();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		I.incremGrade();
		std::cout << I;
		I.decremGrade();
		std::cout << I;
		std::cout << "Trying to decrement grade beyond limit of 150" << std::endl;
		I.decremGrade();
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "DESTRUCTION OF BUREAUCRATS" <<std::endl;
	return (0);
}