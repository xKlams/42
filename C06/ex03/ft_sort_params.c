/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:09:31 by fde-sist          #+#    #+#             */
/*   Updated: 2023/10/05 12:47:43 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_int_tab(int **tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 1;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) < 0)
			{
				swap = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = swap;
			}
			j--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	
}
