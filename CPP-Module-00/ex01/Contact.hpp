/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:58:50 by fde-sist          #+#    #+#             */
/*   Updated: 2025/10/17 15:58:51 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

#define CONTACT_SIZE 5
class Contact {
private:
	std::string contact_info[CONTACT_SIZE];
public:
	void		set_contact();
	void		get_contact(int ID) const;
	std::string	get_info(int index) const;
};


#endif
