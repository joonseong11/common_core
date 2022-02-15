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

#include "./libft/libft.h"
#include "ft_printf.h"
/*
int	base_check(char *base)
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

void	base_print(long num, char *base)
{
	int	len;

	len = 0;
	while (base[len] != 0)
		len++;
	if (num >= len)
	{
		base_print(num / len, base);
		base_print(num % len, base);
	}
	else
		write(1, &base[num], 1);
}
*/
void	ft_putptr(unsigned long long nbr, char *base)
{
	unsigned long long	num;

	num = 0;
	ft_putstr_fd("0x", 1);
	if (base_check(base) == 1)
	{
		if (nbr < 0)
		{
			num = nbr * (-1);
			write(1, "-", 1);
		}
		else
			num = nbr;
		base_print(num, base);
	}
	return ;
}
