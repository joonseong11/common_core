/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:29:07 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/08 23:51:59 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(char c, va_list ap)
{
	if (c == 'c')
		ft_printf_char(va_arg(ap, int));
	else if (c == 's')
		ft_printf_str(va_arg(ap, int));
	else if (c == 'p')
		ft_printf_char(va_arg(ap, int));
	else if (c == 'd')
		ft_printf_char(va_arg(ap, int));
	else if (c == 'i')
		ft_printf_char(va_arg(ap, int));
	else if (c == 'u')
		ft_printf_char(va_arg(ap, int));
	else if (c == 'x')
		ft_printf_char(va_arg(ap, int));
	else if (c == 'X')
		ft_printf_char(va_arg(ap, int));
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
			ft_parse(format[i + 1], ap);
		else
			count += write(1, &format[i], 1);
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
