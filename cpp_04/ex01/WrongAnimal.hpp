#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(WrongAnimal & src);
		WrongAnimal & operator=(WrongAnimal & src);
		std::string	getType(void) const;
		void	makeSound(void) const;
};

#endif