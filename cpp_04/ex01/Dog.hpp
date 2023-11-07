#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(Dog & src);
		Dog & operator=(Dog & src);
		virtual void	makeSound(void) const;
		Brain *get_brain(void);
};

#endif