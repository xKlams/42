#include "libft.h"

void	*memset(void *a, int c, size_t lenght)
{
	char	*p;

	p = (char *)a;
	while (lenght--)
		*(p + lenght) = c;
	return (a);
}
