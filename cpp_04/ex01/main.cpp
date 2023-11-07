#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	int i = 0;
	std::cout << "CREATING 2 DOGS AND 2 CATS" << std::endl;
	Animal *animal_array[4];
	while (i < 2)
		animal_array[i++] = new Dog();
	while (i < 4)
		animal_array[i++] = new Cat();
	
	std::cout << std::endl;
	std::cout << "DELETING 2 DOGS AND 2 CATS" << std::endl;
	i = 0;
	while (i < 4)
		delete animal_array[i++];

	std::cout << std::endl;
	std::cout << "TESTING FOR DEEP OR SHALLOW COPIES OF DOG" << std::endl;
	std::cout << "INITIALIZING DOG INSTANCE AND DOG COPIES" << std::endl;
	std::cout << std::endl;
	//To check whether it's deep or shallow copy, when a dog is copied, the brain should not have same memory address.
	Dog dog1;
	Dog dog2(dog1);
	Dog dog3;
	dog3 = dog2;
	std::cout << std::endl;
	std::cout << "TESTING MEMORY ADDRESS OF BRAIN INSTANCES OF DOG INSTANCES AND DOG COPIES" << std::endl;
	std::cout << "dog1's brain has memory address of " << dog1.get_brain() << std::endl;
	std::cout << "dog2's brain has memory address of " << dog2.get_brain() << std::endl;
	std::cout << "dog3's brain has memory address of " << dog3.get_brain() << std::endl;
	std::cout << std::endl;
	std::cout << "RESULT::All dogs have different memory address, hence deep copies" << std::endl;
	std::cout << std::endl; 

	std::cout << "TESTING FOR DEEP OR SHALLOW COPIES OF CAT" << std::endl;
	std::cout << "INITIALIZING CAT INSTANCE AND CAT COPIES" << std::endl;
	std::cout << std::endl;
	Cat cat1;
	Cat cat2(cat1);
	Cat cat3 = cat2;
	//cat3 = cat2;
	std::cout << std::endl;
	std::cout << "TESTING MEMORY ADDRESS OF BRAIN INSTANCES OF CAT INSTANCES AND CAT COPIES" << std::endl;
	std::cout << "cat1's brain has memory address of " << cat1.get_brain() << std::endl;
	std::cout << "cat2's brain has memory address of " << cat2.get_brain() << std::endl;
	std::cout << "cat3's brain has memory address of " << cat3.get_brain() << std::endl;
	std::cout << std::endl;
	std::cout << "RESULT::All cats have different memory address, hence deep copies" << std::endl;
	std::cout << std::endl; 
	std::cout << "DESTROYING ALL INSTANCES WHEN PROGRAM ENDS" << std::endl; 
	
	system("leaks animal");
	
	return (0);
}