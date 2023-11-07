#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character(std::string name);
		~Character(void);
		Character(Character & src);
		Character & operator=(Character & src);
		std::string const & getName() const;
		AMateria** get_inventory();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif