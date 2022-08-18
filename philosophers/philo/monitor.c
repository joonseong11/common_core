/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:41:00 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/18 20:41:17 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor(t_philo *philo)
{
	int i;
	int kill_;

	kill_ = 0;
	while (1)
	{
		i = 0;
		while (i < philo->info->arg.n_philo)
		{
			pthread_mutex_lock(&philo->info->mutex.print);
			kill_ = philo->info->stat.end;
			if (get_time() - philo[i].last_eat_t > philo->info->arg.die_time)
			{
				philo->info->stat.end++;
				printf("%ld %d died\n", get_time() - philo->info->birth_t, i + 1);
				pthread_mutex_unlock(&philo->info->mutex.print);
				return;
			}
			else
				pthread_mutex_unlock(&philo->info->mutex.print);
			if (kill_)
				return;
			// pthread_mutex_lock(&philo->info->mutex.print);
			// if (philo->info->stat.n_full >= philo->info->arg.must_eat)
			// {
			// 	philo->info->stat.end++;
			// 	pthread_mutex_unlock(&philo->info->mutex.print);
			// 	return ;
			// }
			// else
			// 	pthread_mutex_unlock(&philo->info->mutex.print);
			++i;
		}
	}
}