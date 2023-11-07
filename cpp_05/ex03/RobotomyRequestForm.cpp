#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45, "default"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target){
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "RobotomyRequestForm destructed" <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & src) : AForm(src) {
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm & src) {
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_grade_exec)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "ZzzzZZZZZZzzzzzz" << std::endl;
		if ((rand() % 2) == 0)
			std::cout << this->_target << " has been robotomized successfully" <<std::endl;
		else
			std::cout << "Robotomy failed" <<std::endl;
	}
}