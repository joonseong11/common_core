/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:15:43 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 22:20:35 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atolong(const	char	*str)
{
	long long	minus;
	long long	ret;

	ret = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	if (*str == '-' || *str == '+')
		return (0);
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			ret = ret * 10 + *str - '0';
		else
		{
			if (*str < '0' || *str > '9')
				get_error(NOINT);
			break ;
		}
		str++;
	}
	return (ret * minus);
}
