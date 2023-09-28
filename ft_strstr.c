/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:36:04 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/28 09:52:18 by fde-sist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_increment_and_while(char *str, char *to_find, int *i, int *j)
{
	while (str[*i] == to_find[*j] && to_find[*j])
	{
		*i = *i + 1;
		*j = *j + 1;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	std_str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*to_find || !*str)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			std_str = i;
			ft_increment_and_while(str, to_find, &i, &j);
			if (!to_find[j])
				return (&str[std_str]);
			else
			{
				i = std_str;
				j = 0;
			}
		}
		i++;
	}
	return (NULL);
}
