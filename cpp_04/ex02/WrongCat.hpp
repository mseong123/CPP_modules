#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat & src);
		WrongCat & operator=(WrongCat & src);
		void	makeSound(void) const;
};

#endif