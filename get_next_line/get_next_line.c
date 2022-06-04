/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:57:45 by jujeon            #+#    #+#             */
/*   Updated: 2022/05/22 16:17:47 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len) + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strjoin2(s1, s2, len, str);
	free((void *)s1);
	return (str);
}

char	*leave_newtemp(char *temp)
{
	char	*newtemp;
	size_t	len_newtemp;

	if (ft_strchr(temp, '\n') == 0)
		return (NULL);
	len_newtemp = ft_strlen(temp) - (ft_strchr(temp, '\n') - temp + 1);
	newtemp = ft_substr(temp, (ft_strchr(temp, '\n') - temp + 1), len_newtemp);
	if (newtemp == NULL || *newtemp == '\0')
	{
		free(temp);
		free(newtemp);
		return (NULL);
	}
	free(temp);
	return (newtemp);
}

char	*line_truncate(char *temp)
{
	char	*line;

	if (ft_strchr(temp, '\n') == 0)
		return (temp);
	line = ft_substr(temp, 0, (ft_strchr(temp, '\n') - temp + 1));
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*read_buf(int fd, char *temp)
{
	ssize_t	check;
	char	*buf;

	check = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[0] = '\0';
	while (ft_strchr(buf, '\n') == 0 && check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		if (check < 0)
		{
			free(buf);
			return (NULL);
		}
		if (check > 0)
			temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = read_buf(fd, temp);
	if (temp == NULL)
		return (NULL);
	line = line_truncate(temp);
	temp = leave_newtemp(temp);
	return (line);
}
