/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:08:20 by fde-sist          #+#    #+#             */
/*   Updated: 2023/10/05 12:08:35 by fde-sist         ###   ########.fr       */
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

	i = argc - 1;
	while(i > 0)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
