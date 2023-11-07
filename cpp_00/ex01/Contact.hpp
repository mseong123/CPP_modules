#ifndef CONTACT_H
# define CONTACT_H
#include <string>
#include <iostream>

class Contact {

private:
	std::string _fname;
	std::string	_lname;
	std::string _nname;
	std::string _pnum;
	std::string _secret;

public:
	Contact(void);
	~Contact(void);
	void set_fname(std::string fname);
	void set_lname(std::string lname);
	void set_nname(std::string nname);
	void set_pnum(std::string pnum);
	void set_secret(std::string secret);
	std::string get_fname(void) const;
	std::string get_lname(void) const;
	std::string get_nname(void) const;
	std::string get_pnum(void) const;
	std::string get_secret(void) const;

};

#endif