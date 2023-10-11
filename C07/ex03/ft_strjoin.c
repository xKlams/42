char	*ft_strjoin(int size, char  **strs, char *sep)
{
	char	*str;
	int		i[3];
	int		index;

	i[0] = 0;
	i[1] = 0;
	index = 0;
	while (i[0] < size)
	{
		while (strs[i[0]][i[1]])
		{
			i[1]++;
			index++;
		}
		i[0]++;
		i[1] = 0;
	}
	i[0] = 0;
	while (sep[i[0]])
		i[0]++;
	str = (char *)malloc(i[0] * size * index + 1);
	str[i[0] * size * index] = 0;
	index = 0;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < size)
	{
		while(strs[i[0]][i[1]])
		{
			str[index] = strs[i[0]][i[1]];
			i[1]++;
		 	index++;
		}
		while(sep[i[2]] != 0 && i[0] != size - 1)
		{
			str[index] = sep[i[2]];
			i[2]++;
			index++;
		}
		i[2] = 0;
		i[1] = 0;
		i[0]++;
	}
	return (str);
}
