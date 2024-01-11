#include "libft.h"

int	ft_isalnum(int a)
{
	return ((a <= '9' && a >= '0') || (a <= 'z' && a >= 'a')
		|| (a <= 'Z' && a >= 'A'));
}
