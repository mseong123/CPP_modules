#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5, "default") {
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & src) : AForm(src) {
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & src) {
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_grade_exec)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}