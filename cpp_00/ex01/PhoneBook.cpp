#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void) {
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook (void) {
	return;
}

std::string	PhoneBook::_truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void	PhoneBook::add_contact(void) {
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	pnum;
	std::string	secret;

	while (fname == "")
	{
		std::cout << "Please enter your first name:" << std::endl;
		std::getline(std::cin, fname);
	}
	while (lname == "")
	{
		std::cout << "Please enter your last name:" << std::endl;
		std::getline(std::cin, lname);
	}
	while (nname == "")
	{
		std::cout << "Please enter your nick name:" << std::endl;
		std::getline(std::cin, nname);
	}
	while (pnum == "")
	{
		std::cout << "Please enter your phone number:" << std::endl;
		std::getline(std::cin, pnum);
	}
	while (secret == "")
	{
		std::cout << "Please enter your darkest secret:" << std::endl;
		std::getline(std::cin, secret);
	}
	_contact_array[this->_index].set_fname(fname);
	_contact_array[this->_index].set_lname(lname);
	_contact_array[this->_index].set_nname(nname);
	_contact_array[this->_index].set_pnum(pnum);
	_contact_array[this->_index].set_secret(secret);
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
	std::cout << "Contact added." << std::endl;
}

void	PhoneBook::display_all_contact(void) {
	int	i = 0;

	if (this->_contact_array[0].get_fname() == "")
		std::cout << "No contacts added yet in Phonebook." <<std::endl;
	else
	{
		std::cout << std::setw(10) << "index";
		std::cout << std::setw(1) << "|";
		std::cout << std::setw(10) << "first name";
		std::cout << std::setw(1) << "|";
		std::cout << std::setw(10) << "last name";
		std::cout << std::setw(1) << "|";
		std::cout << std::setw(10) << "nick name" << std::endl;
		while (i < 8)
		{
			if (this->_contact_array[i].get_fname() != "")
			{
				std::cout << std::setw(10) << i;
				std::cout << std::setw(1) << "|";
				std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_fname());
				std::cout << std::setw(1) << "|";
				std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_lname());
				std::cout << std::setw(1) << "|";
				std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_nname()) << std::endl;
			}
			i++;
		}
	}
}

void	PhoneBook::display_specific_contact(void) {
	std::string index_str;

	while (1)
	{
		std::cout << "Please enter an index:" << std::endl;
		std::getline(std::cin, index_str);
		if (index_str.length() != 1 || index_str[0] < '0' || index_str[0] > '7')
			std::cout << "Invalid index!" << std::endl;
		else if (this->_contact_array[index_str[0] - '0'].get_fname() == "")
			std::cout << "Invalid index!" << std::endl;
		else
		{
			std::cout << "first name: " << this->_contact_array[index_str[0] - '0'].get_fname() << std::endl;
			std::cout << "last name: " << this->_contact_array[index_str[0] - '0'].get_lname() << std::endl;
			std::cout << "nick name: " << this->_contact_array[index_str[0] - '0'].get_nname() << std::endl;
			std::cout << "phone number: " << this->_contact_array[index_str[0] - '0'].get_pnum() << std::endl;
			std::cout << "darkest secret: " << this->_contact_array[index_str[0] - '0'].get_secret() << std::endl;
			break;
		}
	}
}

