#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	size_t	new_contact_index;
	size_t	size;
public:
	Phonebook();
	void add();
	void search() const;
};

#endif
