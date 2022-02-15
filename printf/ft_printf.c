/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:29:07 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/14 14:04:55 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int u, int fd)
{
	long long	tmp;

	tmp = u;
	if (tmp > 9)
		ft_putnbr_u(tmp / 10, fd);
	ft_putchar_fd(tmp % 10 + '0', fd);
}

void	ft_parse(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, char), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	//else if (c == 'p')
	//	ft_putpointer(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_putnbr_u(va_arg(ap, int), 1);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else
		return ;
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
			ft_parse(format[i++ + 1], ap);
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
	int b;
	char c;

	a = 1003;
	b = 777;
	c = 'z';
	//printf("%p\n", &a);
	ft_printf("%c", c);
	//ft_printf("%X", 0xF1);
}
