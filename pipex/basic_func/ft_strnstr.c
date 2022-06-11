/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:26:17 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 19:42:42 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while (str[i] != 0 && i < len)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == needle[j] && i + j < len
				&& needle[j] != '\0' && str[i + j] != 0)
				j++;
			if (needle[j] == '\0')
				return ((str + i));
		}
		i++;
	}
	return (NULL);
}

// haystack(짚) : 전체 문장
// needle(바늘) : 찾는 문장
// strnstr() 함수는 종료전까지의 문자들 중 big 문자열 내에서 찾은 little 문자열 중 
// 첫번째로 나온 결과를 찾는다. 문자열은 최대 len의 수까지만 탐색한다.
// 문자열들은 \0을 만나면 더이상 찾지 않는다.