/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:18:48 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/11 18:09:50 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putpointer(unsigned long long p)
{
	ft_putchar_fd("0x");
	ft_putnbr_base(p, "0123456789abcdef");
}
