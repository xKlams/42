#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

#define FIRST_NAME 0
#define LAST_NAME 1
#define NICKNAME 2
#define PHONE_NUMBER 3;
#define SECRET 4

class contact {
private:

	std::string contact_info[5];
public:
	void set_contact();
	void get_contact(int ID) const;
};


#endif
