#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Default Brain constructor called." << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain instance destroyed." << std::endl;
}

Brain::Brain(Brain & src) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
}

Brain & Brain::operator=(Brain & src) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	int i = 0;
	std::string *src_ideas = src.get_ideas();
	if (this != &src)
	{
		while (i < 100)
		{
			this->ideas[i] = src_ideas[i];
			i++;
		}
	}
	return *this;
}

std::string	*Brain::get_ideas(void) {
	return this->ideas;
}
