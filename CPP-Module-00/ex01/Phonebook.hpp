/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:58:15 by fde-sist          #+#    #+#             */
/*   Updated: 2025/10/17 16:00:15 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
