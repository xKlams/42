/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:58:26 by fde-sist          #+#    #+#             */
/*   Updated: 2025/10/17 16:00:33 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;

	std::cout << "> "; 
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break;
		std::cout << "> ";
	}
	if (command != "EXIT")
		std::cout << std::endl;
	std::cout << "Closing the phonebook" << std::endl;
}
