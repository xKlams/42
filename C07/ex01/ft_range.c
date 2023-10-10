#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr = NULL;
	int	size;
	
	if (min >= max)
		return (NULL);	
	size = max - min;
	arr = (int *)(malloc(sizeof(int) * size));
	i = min - 1;
	while (++i < max)
		arr[i - min] = i;
	return(arr);
}
