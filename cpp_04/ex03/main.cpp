#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int	main(void) {
	std::cout << "IMPLEMENTING PDF REQUIREMENT" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << std::endl;
	std::cout << "IMPLEMENTING FURTHER TESTS" << std::endl;
	std::cout << "CREATE NON TEMPLATED FIRE MATERIA" << std::endl;
	AMateria	*fire;
	fire = src->createMateria("fire"); // null
	me->equip(fire);
	std::cout << std::endl;

	std::cout << "EQUIP MORE THAN 4 MATERIAS" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << "TEST DEEP COPY CHARACTER" << std::endl;
	Character	*you = new Character("you");
	tmp = src->createMateria("cure");
	you->equip(tmp);
	tmp = src->createMateria("ice");
	you->equip(tmp);
	Character	*you_copy = new Character(*you);
	std::cout << "MATERIA EQUIPPED BY ORIGINAL CHARACTER" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (you->get_inventory()[i])
		{
			std::cout << "Materia " << i + 1 << " = " << you->get_inventory()[i]->getType() << std::endl;
			std::cout << "Memory address of Materia " << i + 1 << " = " << you->get_inventory()[i] << std::endl;
		}
		i++;
	}
	std::cout << "MATERIA EQUIPPED BY COPY CHARACTER" << std::endl;
	i = 0;
	while (i < 4)
	{
		if (you_copy->get_inventory()[i])
		{
			std::cout << "Materia " << i + 1 << " = " << you_copy->get_inventory()[i]->getType() << std::endl;
			std::cout << "Memory address of Materia " << i + 1 << " = " << you_copy->get_inventory()[i] << std::endl;
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << "USING MATERIA EQUIPPED BY ORIGINAL CHARACTER AND COPY CHARACTER. MAX MATERIA HELD BY EACH CHARACTER IS 4." << std::endl;
	you->use(0, *bob);
	you->use(1, *bob);
	you->use(2, *bob);
	you->use(3, *bob);
	std::cout << std::endl;
	you_copy->use(0, *bob);
	you_copy->use(1, *bob);
	you_copy->use(2, *bob);
	you_copy->use(3, *bob);
	std::cout << std::endl;

	std::cout << "UNEQUIP MATERIA AND USING MATERIA. [Only [cure] and [ice] are equipped currently]" << std::endl;
	std::cout << "TRY TO UNEQUIP NON-EXISTING MATERIAS" << std::endl;
	you->unequip(-1); 
	you->unequip(2);
	you->unequip(18);
	std::cout << "UNEQUIP MATERIA 1 [cure] AND TRY TO USE [cure]" << std::endl;
	tmp = you->get_inventory()[0];
	you->unequip(0);
	delete tmp;
	you->use(0, *bob);
	you->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete you;
	delete you_copy;
	system("leaks finalfantasy");
	return 0;
}