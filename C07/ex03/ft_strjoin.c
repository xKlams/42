char	*ft_strjoin(int size, char  **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		index;
	int		k;

	i = 0;
	j = 0;
	index = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			j++;
			index++;
		}
		i++;
		j = 0;
	}
	i = 0;
	while (sep[i])
		i++;
	str = (char *)malloc(i * size * index + 1);
	str[i * size * index] = 0;
	index = 0;
	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while(strs[i][j])
		{
			str[index] = strs[i][j];
			j++;
		 	index++;
		}
		while(sep[k] != 0 && i != size - 1)
		{
			str [index] = sep[k];
			k++;
			index++;
		}
		k = 0;
		j = 0;
		i++;
	}
	return (str);
}
