/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:50:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/01 01:15:24 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_it(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			n += 1;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (n);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		++i;
	}
	free(str);
	str = NULL;
}

int	put_sentence(char **str, char const *s, char c)
{
	int		i;
	char	*head;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			head = (char *)s;
			while (*s && *s != c)
				++s;
			str[i] = ft_substr(head, 0, (s - head));
			if (str[i] == NULL)
			{
				free_split(str);
				return (0);
			}
			++i;
		}
		else
			++s;
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char *), (find_it(s, c) + 1));
	if (str == NULL)
		return (NULL);
	if (!put_sentence(str, s, c))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}
