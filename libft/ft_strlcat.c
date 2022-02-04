/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:16:29 by jujeon            #+#    #+#             */
/*   Updated: 2021/12/15 17:09:25 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	while (*dst != 0)
	{
		i++;
		dst++;
	}
	while ((i + 1 < size) && src[j] != 0)
	{
		*dst++ = src[j++];
		i++;
	}
	*dst = 0;
	while (src[j] != 0)
	{
		i++;
		j++;
	}
	return (i);
}
