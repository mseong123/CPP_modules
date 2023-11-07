#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_materia[4];
	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource & src);
		MateriaSource & operator=(MateriaSource & src);
		AMateria** get_materia();
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};

#endif