int ft_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_iterative_power(int base, int power)
{
    int a;
    int i;

    a = base;
    i = 0;
    if (!power)
        return (1);
    while (++i < power)
        a *= base;
    return (a);
}

int     ft_check_sign_space(char *str)
{
    int     sign;
    int     i;

    i = 0;
    sign = 2;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        (i)++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign++;
        (i)++;
    }
    if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == 0)
        sign = 0;
    return (sign);
}

int atoi_base(char *nbr, char *base_from)
{
    int i;
    int j;
    int int_nbr;
    i = 0;
    j = 0;
    int_nbr = 0;
    while(nbr[i])
        while(base_from[j])
        {
            if (nbr[i] == base_from[j])
            {
                int_nbr += j * ft_iterative_power(ft_len(base_from), ft_len(nbr) - i - 1);
                j = 0;
                i++;
                break;
            }
            j++;
        }
    if (ft_check_sign_space(nbr) % 2 == 1)
        return(-1 * int_nbr);
    return (int_nbr);
}

int space_needed(int nbr, int len)
{
    int i;
    int minus;

    minus = 0;
    if (nbr < 0)
    {
        minus ++;
        nbr *= -1;
    }
    i = 0;
    while (ft_iterative_power(len, i) < nbr)
        i++;
    printf("%d", i);
    if (minus)
        i++;
    return (i);
}

int     checkbase(char *base)
{
        int             i;
        int             j;

        i = 0;
        if (ft_len(base) < 2)
                return (0);
        while (i < ft_len(base) - 1)
        {
                j = i + 1;
                while (j < ft_len(base))
                {
                        if (base[i] == base[j])
                                return (0);
                        j++;
                }
                if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
                        return (0);
                i++;
        }
        return (1);
}

void    iteration(long int nbr, char *base, int counter, char *nb)
{
    if (nbr == 0 && counter == 0)
        nb[0] = base[0];
    if (nbr < 0)
    {
        nb[counter] = '-';
        nbr *= -1;
        counter++;
    }
    if (nbr && checkbase(base))
    {
        nb[counter] = nbr % ft_len(base);
        iteration(nbr / ft_len(base), base, ++counter, nb);
    }
}

char    *ft_putnbr_base(int nbr, char *base)
{
    char    *nb;

    nb = (char *)malloc(space_needed(nbr, ft_len(base)));
    nb[space_needed(nbr, ft_len(base))] = 0;
    iteration((long int) nbr, base, 0, nb);
    return(nb);
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    char    *number;
    int     num_dec;

    num_dec = atoi_base(nbr, base_from);
    number = ft_putnbr_base(num_dec, base_to);
    return(number);

}