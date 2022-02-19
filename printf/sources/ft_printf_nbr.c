/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:36:10 by jujeon            #+#    #+#             */
/*   Updated: 2021/12/27 14:15:29 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_nbr_body(int n, int *p)
{
	long long	tmp;

	if (n < 0)
	{
		ft_printf_char('-');
		tmp = (long long)n * (-1);
		(*p)++;
	}
	else
		tmp = n;
	if (tmp > 9)
		ft_printf_nbr_body(tmp / 10, p);
	ft_printf_char(tmp % 10 + '0');
	(*p)++;
}

int	ft_printf_nbr(int n)
{
	int		i;
	int		*p;

	i = 0;
	p = &i;
	ft_printf_nbr_body(n, p);
	return (i);
}
