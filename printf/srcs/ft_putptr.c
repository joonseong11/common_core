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

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int	ft_printf_ptr(unsigned long long nbr, char *base)
{
	unsigned long long	num;

	num = 0;
    ft_printf_str("0x", 1);
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
	return ();
}
