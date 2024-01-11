/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:15:36 by fde-sist          #+#    #+#             */
/*   Updated: 2023/10/04 09:43:40 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_a(int a, int b, char *str, int aux)
{
	int	i;
	int	c;

	i = 0;
	c = a;
	if (aux)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		if (!b)
			return (1);
		while (i < b - 1)
		{
			a *= c;
			i++;
		}
		return (a);
	}
	return (a);
}

int	ft_check_sign_space(char *str, int *i)
{
	int	sign;

	(*i)++;
	sign = 2;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign++;
		(*i)++;
	}
	if (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13) || str[*i] == 0)
		sign = 0;
	return (sign);
}

int	ft_checkbase(char *base, int aux, int *num, int *sign)
{
	int		i;
	int		j;

	if (aux == 1 && (*sign % 2))
		*num = *num * (-1);
	i = 0;
	if (ft_a(0, 0, base, 1) < 2)
		return (0);
	while (i < ft_a(0, 0, base, 1) - 1)
	{
		j = i + 1;
		while (j < ft_a(0, 0, base, 1))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

void	ft_a_2(int i[2], int *num, int *sign, char *str)
{
	*num = 0;
	i[0] = -1;
	*sign = ft_check_sign_space(str, &i[0]);
	i[0]--;
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	i[2];
	int	sign;

	ft_a_2(i, &num, &sign, str);
	if (ft_checkbase(base, 0, 0, 0) && sign)
	{
		while (++(i[0]) < ft_a(0, 0, str, 1))
		{
			i[1] = -1;
			while (++(i[1]) < ft_a(0, 0, base, 1))
			{
				if (str[i[0]] == base[i[1]])
				{
					num += i[1] * ft_a(ft_a(0, 0, base, 1),
							ft_a(0, 0, str, 1) - i[0] - 1, str, 0);
					break ;
				}
				else if (i[1] == ft_a(0, 0, base, 1) - 1)
					return (num / ft_a(10, ft_a(0, 0, str, 1) - i[0], "", 0));
			}
		}
	}
	i[0] = ft_checkbase("", 1, &num, &sign);
	return (num);
}
