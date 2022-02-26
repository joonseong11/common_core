/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:40 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/25 20:34:48 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_ptrbase(unsigned long num, const char *base, int *p)
{
	unsigned long	len;

	len = 0;
	while (base[len] != 0)
		len++;
	if (num >= len)
	{
		ft_printf_ptrbase(num / len, base, p);
		ft_printf_ptrbase(num % len, base, p);
	}
	else
	{
		write(1, &base[num], 1);
		(*p)++;
	}
}

int	ft_printf_ptr(void *nbr, const char *base)
{
	int				i;
	int				*p;
	unsigned long	nbr1;

	i = 2;
	p = &i;
	nbr1 = (unsigned long)nbr;
	ft_printf_str("0x");
	if (base_check(base) == 1)
	{
		ft_printf_ptrbase(nbr1, base, p);
	}
	else
		return (0);
	return (*p);
}
