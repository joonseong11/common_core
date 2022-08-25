/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:00:58 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/22 16:02:11 by jujeon           ###   ########.fr       */
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
	if (strstr(str, "is eating"))
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
