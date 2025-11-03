/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <fde-sist@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:58:45 by fde-sist          #+#    #+#             */
/*   Updated: 2025/10/17 16:19:55 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
	}
	for (size_t j = 0; j < (size_t)argc - 1; j++)
	{
		if (j > 0)
			std::cout << " ";
		for (size_t i = 0; argv[j+1][i]; i++)
			std::cout << (char)std::toupper(argv[j + 1][i]);
	}
	std::cout << std::endl;
}
