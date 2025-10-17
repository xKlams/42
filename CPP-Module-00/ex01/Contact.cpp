/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:58:13 by fde-sist          #+#    #+#             */
/*   Updated: 2025/10/17 16:02:35 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

void Contact::set_contact()
{
	std::string contact_fields[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Please enter the "<< contact_fields[i] << " of your contact" << std::endl;
		if (!std::getline(std::cin, this->contact_info[i]))
			break;
		if (contact_info[i].length() == 0)
		{
			std::cout << "Empty string provided, please enter a non-empty string" << std::endl;
			i--;
		}
		else if (i == 3 && this->contact_info[i].find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "That's not a phone number!" << std::endl;
			i--;
		}
	}
	std::cout << "Contact added correctly" << std::endl;
}

void Contact::get_contact(int ID) const
{
	std::cout << "|" << std::setfill(' ') << std::setw(10) << ID << "|";
	for (int i = 0; i < 3; i++)
	{
		if (this->contact_info[i].length() <= 10)
			std::cout << std::setw(10) << contact_info[i] << "|";
		else
			std::cout << std::setw(10) << contact_info[i].substr(0,9) + "." << "|";
	}
	std::cout << std::endl;
}

std::string Contact::get_info(int index) const
{
	return (this->contact_info[index]);
}
