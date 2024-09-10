#include <stdlib.h>

int find_size(long int nbr)
{
    int size = 2;
    if (nbr <0)
    {
        size++;
        nbr *= -1;
    }
    while(nbr > 9)
    {
        nbr /= 10;
        size++;
    }
    return size;
}

char    *ft_itoa_aux(long int nbr)
{
    char    *str;
    int     index = 1;
    int size = find_size(nbr);

    str = malloc(size);
    if (!str)
        return (NULL);
    if (nbr == 0)
        str[0] = '0';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr *= -1;
    }
    while (nbr > 0)
    {
        str[size - index++ - 1] = '0' + (nbr % 10);
        nbr /= 10;
    }
    str[size] = 0;
    return (str);
}
char    *ft_itoa(int nbr)
{
    return(ft_itoa_aux((long int) nbr));
}

int main()
{
    printf("%s\n", ft_itoa(-2147483648));
}
