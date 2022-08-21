/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:47:53 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/21 23:05:56 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (haystack == NULL)
		return (NULL);
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

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	smart_timer(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

void	mutexde_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_destroy(philo[i].left);
	pthread_mutex_destroy(&philo->info->mutex.print);
	i = -1;
	free(philo->left);
	free(philo);
}
