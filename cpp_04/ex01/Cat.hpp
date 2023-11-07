#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(Cat & src);
		Cat & operator=(Cat & src);
		virtual void	makeSound(void) const;
		Brain *get_brain(void);
};

#endif