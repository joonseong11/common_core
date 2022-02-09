/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 01:39:00 by jujeon            #+#    #+#             */
/*   Updated: 2021/12/07 15:13:00 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	if (dst == 0 && src == 0)
		return (NULL);
	while (i)
	{
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
		i--;
	}
	return (dst);
}
