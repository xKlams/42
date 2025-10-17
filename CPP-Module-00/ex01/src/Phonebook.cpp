/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:17:39 by fde-sist          #+#    #+#             */
/*   Updated: 2025/07/23 10:18:15 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Phonebook.hpp"
#include <cstddef>
#include <iostream>

void	Phonebook::add()
{
	this->contacts[new_contact_index].set_contact();
	if (size < 8)
		this->size++;
	this->new_contact_index = (this->new_contact_index + 1) % 8;
}

Phonebook::Phonebook()
{
	this->new_contact_index = 0;
	this->size = 0;
	return;
}

void	Phonebook::search() const
{
	std::string	tab_names[4] = {"index", "first name", "last name", "nickname"};
	std::string	contact_fields[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string	choosen_index;

	if (this->size == 0)
	{
		std::cout << "Your Phonebook is empty" << std::endl;
		return ;
	}
	for (int i = 0; i <= 44; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10);
	for (int i = 0; i < 4; i++)
		std::cout << std::setw(10) << tab_names[i] << "|";
	std::cout << std::endl;
	for (size_t i = 0; i < this->size; i++)
		this->contacts[i].get_contact(i);
	for (int i = 0; i <= 44; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "Insert index: ";
	std::getline(std::cin, choosen_index);
	while (choosen_index.length() != 1 || !((size_t)choosen_index[0] >= '0' && (size_t)choosen_index[0] <= this->size + '0'))
	{
		std::cout << "Provided input is not a valid index" << std::endl;
		std::cout << "Insert index: ";
		std::getline(std::cin, choosen_index);
	}
	for (int i = 0; i < CONTACT_SIZE; i++)
	{
		std::cout << contact_fields[i] << ": " << this->contacts[choosen_index[0] - '0'].get_info(i) << std::endl;
	}
}
