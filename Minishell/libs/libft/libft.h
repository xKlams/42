/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:51:10 by fde-sist          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:51 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalnum(int a);
int			ft_isalpha(int a);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isprint(int a);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s0, const void *s2, size_t n);
int			ft_atoi(const char *nptr);
long int	ft_long_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
size_t		ft_wlen(const char *str);
size_t		ft_strlcpy(char	*dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *a, int c, size_t lenght);
void		*ft_memcpy(void *dest, const void *src, size_t lenght);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nmeb, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_fw(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(void *c);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t		count_words(const char *s, char c);
int			ft_isspace(int c);

#endif
