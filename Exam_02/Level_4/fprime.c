#include <unistd.h>

int atoi(char *str)
{
    int ans = 0;
    while(*str)
    {
        ans *= 10;
        ans += *str - '0';
        str++;
    }
    return (ans);
}

void    print_num(int num)
{
    char to_print;
    if(!num)
        return;
    to_print = '0' + num % 10;
    print_num(num/10);
    write(1, &to_print, 1);
    
}

void    fprime(int num)
{
    int i = 2;
    char    factor;
    if(num == 1)
        write(1, "1", 1);
    while( num > 1)
    {
        if (num % i == 0)
        {
            num /= i;
            print_num(i);
            if (num != 1)
                write(1, "*", 1);
        }
        else
            i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        fprime(atoi(argv[1]));
    }
    write(1, "\n", 1);
}