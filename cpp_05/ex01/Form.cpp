#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _grade_sign(50), _grade_exec(100) {
	std::cout << "default unsigned form constructed with required grade: 50 to sign and required grade:100 to execute" << std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec) {
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "Unsigned Form named " << this->_name << " with required grade: " << this->_grade_sign << " to sign and required grade: " 
		<< this->_grade_exec << " to execute is constructed"<<std::endl;
}

Form::~Form(void) {
	if (this->_signed)
		std::cout << "Signed Form named " << this->_name << " with required grade: " << this->_grade_sign << " to sign and required grade: " 
		<< this->_grade_exec << " to execute is destructed"<<std::endl;
	else
		std::cout << "Unsigned Form named " << this->_name << " with required grade: " << this->_grade_sign << " to sign and required grade: " 
		<< this->_grade_exec << " to execute is destructed"<<std::endl;
}

Form::Form(Form & src) : _name(src.getName()), _signed(src.getSigned()), _grade_sign(src.getGradeSign()), _grade_exec(src.getGradeExec()) {
	std::cout << "Copy Constructor called" << std::endl;
}

Form & Form::operator=(Form & src) {
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &src)
	{
		//below commented out because attributes are constant hence can't copy
		//this->_name = src.getName();
		this->_signed = src.getSigned();
		//this->_grade_sign = src.getGradeSign();
		//this->_grade_exec = src.getGradeExec();
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

const int Form::getGradeSign() const {
	return this->_grade_sign;
}

const int Form::getGradeExec() const {
	return this->_grade_exec;
}

void Form::beSigned(Bureaucrat & src) {
	if (src.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form & src) {
	if (src.getSigned())
		return (o << "Signed Form " << src.getName() << ", required grade to sign: " << src.getGradeSign() << ", required grade to execute: " 
		<< src.getGradeExec() <<std::endl);
	else 
		return (o << "Unsigned Form " << src.getName() << ", required grade to sign: " << src.getGradeSign() << ", required grade to execute: " 
		<< src.getGradeExec() <<std::endl);
}