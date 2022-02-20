/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:40 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/09 15:59:42 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	base_check(const char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	base_print(long long num, const char *base, int *p)
{
	int			len;

	len = 0;
	while (base[len] != 0)
		len++;
	if (num >= len)
	{
		base_print(num / len, base, p);
		base_print(num % len, base, p);
	}
	else
	{
		write(1, &base[num], 1);
		(*p)++;
	}
}

int	ft_printf_nbrbase(unsigned int nbr, const char *base)
{
	long long	num;
	int			i;
	int			*p;

	i = 0;
	p = &i;
	num = 0;
	if (base_check(base) == 1)
	{
		num = nbr;
		base_print(num, base, p);
	}
	return (*p);
}
