/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:00:58 by jujeon            #+#    #+#             */
/*   Updated: 2022/09/03 19:21:12 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	philo_print(t_philo *philo, t_info *info, int idx, char *str)
{
	sem_wait(philo->info.sema.print);
	printf("%ld %d %s\n", get_time() - info->birth_t, idx + 1, str);
	if (ft_strnstr(str, "is eating", 9))
	{
		philo->last_eat_t = get_time();
		if (++(philo->eat_cnt) == info->arg.must_eat)
		{
			sem_post(info->sema.eat_checker);
			return ;
		}
	}
	sem_post(philo->info.sema.print);
}

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
			while (str[i + j] == needle[j] && i + j < len && needle[j] != '\0'
				&& str[i + j] != 0)
				j++;
			if (needle[j] == '\0')
				return ((str + i));
		}
		i++;
	}
	return (NULL);
}

long long	p_atoi(const char *str)
{
	long long	ret;

	ret = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			ret = ret * 10 + *str - '0';
			if (ret > INT_MAX || ret < INT_MIN)
				return (ERROR);
		}
		else
			return (ERROR);
		str++;
	}
	return (ret);
}
/*
	error cases are
	- input of must_eat is 0, negative, combine of characters or super big number
	- then p_atoi memo return -1
*/