#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		~Ice(void);
		Ice(Ice & src);
		Ice & operator=(Ice & src);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif