void	initialize(int *i, int *index)
{
	*index = 0;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
}

void	ft_set_index(char **strs, int *i, int *index, int *size)
{
	initialize(i, index);
	while (i[0] < *size)
	{
		while (strs[i[0]][i[1]])
		{
			(i[1])++;
			(*index)++;
		}
		(i[0])++;
		i[1] = 0;
	}
}

void	initialize_and_augment(int *i)
{
	i[2] = 0;
	i[1] = 0;
	(i[0])++;
}

void	a_really_nice_while(char *sep, char *str, int *i, int *index)
{
	str[*index] = sep[i[2]];
	i[2]++;
	(*index)++;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i[3];
	int		index;

	ft_set_index(strs, i, &index, &size);
	i[0] = 0;
	while (sep[i[0]])
		i[0]++;
	str = (char *)malloc(i[0] * size * index + 1);
	str[i[0] * size * index] = 0;
	initialize(i, &index);
	while (i[0] < size)
	{
		while (strs[i[0]][i[1]])
		{
			str[index] = strs[i[0]][i[1]];
			i[1]++;
			index++;
		}
		while (sep[i[2]] != 0 && i[0] != size - 1)
			a_really_nice_while(sep, str, i, &index);
		initialize_and_augment(i);
	}
	return (str);
}
