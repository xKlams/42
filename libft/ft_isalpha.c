#include "libft.h"

int	ft_isalpha(int a)
{
	return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
}
