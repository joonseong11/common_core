/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:20:53 by jujeon            #+#    #+#             */
/*   Updated: 2021/12/15 20:26:45 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_str_body(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_printf_char(s[i]);
		i++;
	}
	return (i);
}

int	ft_printf_str(char *s)
{
	int	count;

	count = 0;
	if (s == 0)
		count = ft_printf_str_body("(null)");
	else
		count = ft_printf_str_body(s);
	return (count);
}
