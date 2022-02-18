//
// Created by APPLE on 2022/02/18.
//

int	ft_putnbr_u(unsigned int u, static int i)
{
    long long	tmp;

    tmp = u;
    if (tmp > 9)
        ft_putnbr_u(tmp / 10, i);
    ft_putchar_fd(tmp % 10 + '0', 1);

}

int ft_printf_unbr(unsigned int u)
{
    static int  i;
    ft_putnbr_u(u, i);
    return (i);
}