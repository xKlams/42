#include <stdlib.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int     count_words(char *str)
{
    int i = 0;
	int	ans = 0;
    while(is_space(str[i]))
		i++;
	while(str[i])
	{
    	while(is_space(str[i]))
			i++;
		if (str[i])
			ans++;
		while(!is_space(str[i]) && str[i])
			i++;
	}
	return (ans);
}

int	word_len(char *str)
{
	int i = 0;
	while(!is_space(str[i]) && str[i])
		i++;
	return (i);
}

char    **ft_split(char *str)
{
	char **output;
	int words = count_words(str);
	int j = 0;
	int i = 0;
	
	output = (char **) malloc(sizeof(char *) * (words + 1));
	if (!output)
		return (NULL);
	output[words] = NULL;
	while(i < words)
	{
		while (is_space(*str))
			str++;
		output[i] = (char *) malloc(word_len(str) + 1);
		if (!output[i])
			return (NULL);
		while(!is_space(*str) && *str)
			output[i][j++] = *(str++);
		output[i++][j] = 0;
		j = 0;
	}
	return (output);
}
int main()
{
	int		idx;
	char	**tab;

	idx = 0;
	tab = ft_split("    The prophecy i s 	true lol 		   ici");
	while (idx < 7)
	{
		printf("String %d : %s\n", idx, tab[idx]);
		idx++;
	}
	printf("test = %d\n", tab[7] == NULL);
	return (0);
}