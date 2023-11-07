#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	std::cout << "A default Bureaucrat is constructed" <<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << "A Bureaucrat named " << name << " and with grade " << grade << " is constructed" <<std::endl;
		this->_grade = grade;
	}
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "A Bureaucrat named " << this->_name << " and with grade " << this->_grade << " is destroyed" <<std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat & src): _name(src.getName()), _grade(src.getGrade()) {
	std::cout << "Copy constructor called" <<std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat & src) {
	if (this != &src)
	{
		//this->_name = src.getName();
		this->_grade = src.getGrade();
		std::cout << "Copy assignment operator called" <<std::endl;
	}
	return *this;
}

const std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incremGrade(void) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else 
	{
		std::cout << "Incrementing " << this->_name << "'s Grade" << std::endl;
		this->_grade--;
	}
}

void Bureaucrat::decremGrade(void) {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << "Decrementing " << this->_name << "'s Grade" << std::endl;
		this->_grade++;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

//even if src.beSigned throw an exception, the codes following the function doesn't run.
void	Bureaucrat::signForm(Form & src) {
	if (this->_grade <= src.getGradeSign())
		std::cout << this->_name << " signed form " << src.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign form " << src.getName() << " because grade's too low"<< std::endl;
	src.beSigned(*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & src)
{
	return o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
}