#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137, "default") {
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & src) : AForm(src) {
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm & src) {
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &src)
	{
		//below commented out because attributes are constant hence can't copy
		//this->_name = src.getName();
		this->_signed = src.getSigned();
		//this->_grade_sign = src.getGradeSign();
		//this->_grade_exec = src.getGradeExec();
		this->_target = src.getTarget();
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_grade_exec)
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file(this->_target + "_shrubbery");
		file << "     *     \n";
		file << "    ***    \n";
		file << "   *****   \n";
		file << "  *******  \n";
		file << " ********* \n";
		file << "    |||    \n";
		file.close();
	}
}

