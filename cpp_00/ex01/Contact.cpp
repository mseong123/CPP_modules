#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void	Contact::set_fname(std::string fname) {
	this->_fname = fname;
}

void	Contact::set_lname(std::string lname) {
	this->_lname = lname;
}

void	Contact::set_nname(std::string nname) {
	this->_nname = nname;
}

void	Contact::set_pnum(std::string pnum) {
	this->_pnum = pnum;
}

void	Contact::set_secret(std::string secret) {
	this->_secret = secret;
}

std::string	Contact::get_fname(void) const {
	return (this->_fname);
}

std::string	Contact::get_lname(void) const {
	return (this->_lname);
}

std::string	Contact::get_nname(void) const {
	return (this->_nname);
}

std::string	Contact::get_pnum(void) const {
	return (this->_pnum);
}

std::string	Contact::get_secret(void) const {
	return (this->_secret);
}