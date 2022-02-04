/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:08:45 by jujeon            #+#    #+#             */
/*   Updated: 2021/12/05 19:24:33 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (*str)
	{
		str++;
		i++;
	}	
	while (i)
	{
		if (*str == (char)c)
			return (str);
		str--;
		i--;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}
