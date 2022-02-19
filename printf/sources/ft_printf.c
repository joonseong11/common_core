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

int	ft_parse(char c, va_list ap)
{
	const char	*l_hex = "0123456789abcdef";
	const char	*u_hex = "0123456789ABCDEF";

	if (c == 'c')
		return (ft_printf_char(va_arg(ap, int)));
	else if (c == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(ap, unsigned long long), l_hex));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printf_unbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_printf_nbrbase(va_arg(ap, unsigned int), l_hex));
	else if (c == 'X')
		return (ft_printf_nbrbase(va_arg(ap, unsigned int), u_hex));
	else if (c == '%')
		return (ft_printf_char('%'));
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
//
//#include <stdio.h>
//
//int	main(void)
//{
//	int	a;
//
//	a = 10;
//	printf("^ : printf's output, return of printf : %d\n", printf("%p \n", &a));
//	printf(" : ft_printf's output, return of ft_printf : %d\n", ft_printf("%p", &a));
//}