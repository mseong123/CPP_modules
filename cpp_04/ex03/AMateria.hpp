#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria & src);
		AMateria & operator=(AMateria & src);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif