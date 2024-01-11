/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:01:37 by fde-sist          #+#    #+#             */
/*   Updated: 2023/10/05 12:06:30 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
