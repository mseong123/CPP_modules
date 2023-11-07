#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Default constructor for Intern called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern destructed" << std::endl;
}

Intern::Intern(Intern & src) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern & Intern::operator=(Intern & src) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}
// below 3 member functions to create appropriate malloc-ed Forms and return value of AForm (since it's the parent class)
AForm *Intern::makeShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makePresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	int i = 0;
	/*1) AForm * is the return value of the functions in the array. This is standard in first part of declaration of function type 
	2) (*Intern::makeFormArray[3]) is the function reference itself which in this case is array of 3 (hence like a array of pointers to *functions) 
	and also that these functions belong in Intern class.
	3) (std::string) is the parameter of the functions*/
	AForm *(Intern::*makeFormArray[3])(std::string) = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string form_name[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	while (i < 3)
	{
		if (form_name[i] == form)
		{
			std::cout << "Intern creates " << form_name[i] << std::endl;
			//*makeFormArray[i] this is accessing the array of members and dereferencing it to get the function, ie if i = 0 then this->makePresidential(target)
			return (this->*makeFormArray[i])(target);
		}
		i++;
	}
	std::cout << "Form does not exist" << std::endl;
	return (NULL);
}

/*
BELOW C EQUIVALENT SHOWS HOW ARRAY OF FUNCTION POINTERS ABOVE WORK
#include <stdlib.h>
#include <stdio.h>
int *myfunction(void) {
    int *arr = malloc(4 * sizeof(int));
    arr[0] = 5;
    return arr;
}

int main() {
    int *(*f)(void) = myfunction;
	//DEREFERENCE f using *f;
    printf("%d\n", *f());
}*/