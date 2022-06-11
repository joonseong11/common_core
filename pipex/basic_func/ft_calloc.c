/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:19:29 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 19:42:44 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < count * size)
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
