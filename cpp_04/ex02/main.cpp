#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	//AAnimal test; //will throw error;
	std::cout << "INSTANTIATION OF DOG AND CAT INSTANCES USING ABSTRACT ANIMAL CLASS" << std::endl;
	AAnimal *dog = new Dog();
	AAnimal *cat = new Cat();
	std::cout << std::endl;
	
	std::cout << "USING PURE METHODS IN INHERITED DOG AND CAT INSTANCES" << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "DELETE NEW CLASSES" << std::endl;
	delete dog;
	delete cat;
	std::cout << std::endl;

	std::cout << "CREATION OF DOG INSTANCE AND COPIES" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	Dog dog3;
	dog3 = dog2;
	std::cout << std::endl;
	std::cout << "TESTING FOR DEEP OR SHALLOW COPIES OF DOG" << std::endl;
	std::cout << "TESTING MEMORY ADDRESS OF BRAIN INSTANCES OF DOG INSTANCES AND DOG COPIES" << std::endl;
	std::cout << "dog1's brain has memory address of " << dog1.get_brain() << std::endl;
	std::cout << "dog2's brain has memory address of " << dog2.get_brain() << std::endl;
	std::cout << "dog3's brain has memory address of " << dog3.get_brain() << std::endl;
	std::cout << std::endl;
	std::cout << "RESULT::All dogs have different memory address, hence deep copies" << std::endl;
	std::cout << std::endl; 

	std::cout << "CREATION OF CAT INSTANCE AND COPIES" << std::endl;
	Cat cat1;
	Cat cat2(cat1);
	Cat cat3;
	cat3 = cat2;
	std::cout << std::endl;
	std::cout << "TESTING FOR DEEP OR SHALLOW COPIES OF CAT" << std::endl;
	std::cout << "TESTING MEMORY ADDRESS OF BRAIN INSTANCES OF CAT INSTANCES AND CAT COPIES" << std::endl;
	std::cout << "cat1's brain has memory address of " << cat1.get_brain() << std::endl;
	std::cout << "cat2's brain has memory address of " << cat2.get_brain() << std::endl;
	std::cout << "cat3's brain has memory address of " << cat3.get_brain() << std::endl;
	std::cout << std::endl;
	std::cout << "RESULT::All cats have different memory address, hence deep copies" << std::endl;
	std::cout << std::endl; 
	std::cout << "DESTROYING ALL INSTANCES WHEN PROGRAM ENDS" << std::endl;
	
	return (0);
}