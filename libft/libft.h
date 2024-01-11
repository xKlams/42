#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int	ft_isalnum(int a);
int	ft_isalpha(int a);
int	ft_isascii(int a);
int	ft_isdigit(int a);
int	ft_isprint(int a);
void	*memset(void *a, int c, size_t lenght);
int	ft_strlen(char *string);

#endif
