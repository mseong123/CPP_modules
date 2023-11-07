#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal(void);
		virtual ~AAnimal(void) = 0;
		AAnimal(AAnimal & src);
		AAnimal & operator=(AAnimal & src);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif