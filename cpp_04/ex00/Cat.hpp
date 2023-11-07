#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat & src);
		Cat & operator=(Cat & src);
		virtual void	makeSound(void) const;
};

#endif