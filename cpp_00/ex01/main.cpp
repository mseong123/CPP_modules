#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	std::cout << "WELCOME TO PHONEBOOK SOFTWARE [Add up to 8 contacts]" << std::endl;
	while (1)
	{
		std::cout << "Please enter a command [ADD/SEARCH/EXIT]:" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
		{
			phonebook.display_all_contact();
			phonebook.display_specific_contact();
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Wrong command entered. Please try again." << std::endl;
	}
	std::cout << "Program exiting." << std::endl;
	return (0);
}