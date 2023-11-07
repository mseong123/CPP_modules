#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal & src);
		Animal & operator=(Animal & src);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif