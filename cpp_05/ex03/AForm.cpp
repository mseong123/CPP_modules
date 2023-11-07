#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _grade_sign(50), _grade_exec(100), _target("default") {
	std::cout << "default unsigned form constructed with required grade: 50 to sign and required grade:100 to execute and target of default" << std::endl;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec, std::string target) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec), _target(target) {
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << "Unsigned Form named " << this->_name << " with required grade: " << this->_grade_sign << " to sign and required grade: " 
		<< this->_grade_exec << " to execute and target of " << this->_target << " is constructed"<<std::endl;
}

AForm::~AForm(void) {
}

AForm::AForm(AForm & src) : _name(src.getName()), _signed(src.getSigned()), _grade_sign(src.getGradeSign()), _grade_exec(src.getGradeExec()) {
	std::cout << "Copy Constructor called" << std::endl;
}

AForm & AForm::operator=(AForm & src) {
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

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

const int AForm::getGradeSign() const {
	return this->_grade_sign;
}

const int AForm::getGradeExec() const {
	return this->_grade_exec;
}

std::string AForm::getTarget() const {
	return this->_target;
}

void AForm::beSigned(Bureaucrat & src) {
	if (src.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, AForm & src) {
	if (src.getSigned())
		return (o << "Signed Form " << src.getName() << ", required grade to sign: " << src.getGradeSign() << ", required grade to execute: " 
		<< src.getGradeExec() << " and target of " << src.getTarget() <<std::endl);
	else 
		return (o << "Unsigned Form " << src.getName() << ", required grade to sign: " << src.getGradeSign() << ", required grade to execute: " 
		<< src.getGradeExec() << " and target of " << src.getTarget() << std::endl);
}