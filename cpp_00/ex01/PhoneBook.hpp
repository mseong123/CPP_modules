#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {

private:

	Contact 	_contact_array[8];
	int			_index;
	std::string	_truncate(std::string str);
	

public:


	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(void);
	void	display_all_contact(void);
	void	display_specific_contact(void);
};

#endif
