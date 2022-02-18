/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:29:07 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/07 20:22:32 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int     ft_parse(char c, va_list ap)
{
    const char *l_hexa = "0123456789abcdef";
    const char *u_hexa = "0123456789ABCDEF";
    int         count;

    count = 0;
    if (c == 'c')
        return = ft_printf_char(va_arg(ap, int), 1);
    else if (c == 's')
        return = ft_printf_str(va_arg(ap, char *), 1);
    else if (c == 'p')
        ft_printf_ptr(va_arg(ap, unsigned long long), l_hexa);
    else if (c == 'd' || c == 'i')
        ft_putnbr_fd(va_arg(ap, int), 1);
    else if (c == 'u')
        ft_putnbr_u(va_arg(ap, int), 1);
    else if (c == 'x')
        ft_putnbr_base(va_arg(ap, int), l_hexa);
    else if (c == 'X')
        ft_putnbr_base(va_arg(ap, int), u_hexa);
    else
        return (0);
}

int	ft_body(const char *format, va_list ap)
{
    int	i;
    int	count;

    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%')
            count += ft_parse(format[i++ + 1], ap);
        else
            count += write(1, &format[i], 1);
        ++i;
    }
    return (count);
}

int	ft_printf(const char *format, ...)
{
    int		count;
    va_list	ap;

    va_start(ap, format);
    count = ft_body(format, ap);
    va_end(ap);
    return (count);
}

#include <stdio.h>

int	main(void)
{
	int	a;

	a = 10;
	printf("return of printf : %d\n", printf("%p \n", &a));
    printf("return of printf : %d\n", ft_printf("%p", &a));
}