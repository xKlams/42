#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include "contact.hpp"

class phonebook
{
private:
	contact contacts[8];
	size_t	new_contact_index;
	size_t	size;
public:
	phonebook();
	void add();
	void search() const;
};

#endif
