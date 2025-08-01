#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

#define CONTACT_SIZE 5
class contact {
private:
	std::string contact_info[CONTACT_SIZE];
public:
	void		set_contact();
	void		get_contact(int ID) const;
	std::string	get_info(int index) const;
};


#endif
