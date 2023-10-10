#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
	{
		*range = (NULL);
		return (0);
	}
	size = max - min;
	*range = (int *)(malloc(sizeof (int) * size));
	i = min - 1;
	while (++i < max)
		(*range)[i - min] = i;
	return (size);
}
