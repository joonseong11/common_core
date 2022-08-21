/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:41:00 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/22 00:22:51 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_philo *philo, t_info *info)
{
	int	i;
	int	kill_flag;

	kill_flag = 0;
	while (1)
	{
		i = -1;
		while (++i < philo->info->arg.n_philo)
		{
			pthread_mutex_lock(&philo->info->mutex.print);
			kill_flag = philo->info->stat.end;
			if (get_time() > philo[i].last_eat_t + (size_t)info->arg.die_time)
			{
				philo->info->stat.end++;
				printf("%ld %d died\n", get_time() - info->birth_t, i + 1);
				pthread_mutex_unlock(&philo->info->mutex.print);
				return ;
			}
			else
				pthread_mutex_unlock(&philo->info->mutex.print);
			if (kill_flag)
				return ;
		}
	}
}
