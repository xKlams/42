#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	size;

	size = max - min;
	if (size <= 0)
		return (NULL);
	arr = (int *)(malloc(sizeof(int) * size));
	i = min;
	while (++i < max)
		arr[min-i] = i;
	return(arr);
}
