/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:23:25 by fde-sist          #+#    #+#             */
/*   Updated: 2023/10/02 20:09:55 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	checkbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_len(base) < 2)
		return (0);
	while(i	< ft_len(base) - 1)
	{
		j = i + 1;
		while (j < ft_len(base))
		{
			if (base[i] == base[j] || base[i] == '+' || base[j] == '+')
				return (0);
			if (base[j] == '-' || base [j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}

void	iteration(int nbr, char *base, int counter)
{
	if (nbr == 0 && counter == 0)
		write(1, "0", 1);
	if (nbr ==  -2147483648)
	{
		write(1, "-", 1);
		write(1, base + nbr % ft_len(base), 1);
		nbr /= ft_len(base);
		nbr *= -1;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr && checkbase(base))
	{
		iteration(nbr / ft_len(base), base, ++counter);
		write(1, base + nbr % ft_len(base), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	iteration(nbr, base, 0);
}
