/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:47:53 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/18 20:50:44 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == ERROR)
		return (ERROR);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void smart_timer(size_t time)
{
	size_t start;

	start = get_time();
	// if (start == ERROR)
	// return (ERROR);
	while (get_time() - start < time)
		usleep(100);
}

void philo_print(t_philo *philo, t_info *info, int idx, char *str)
{
	pthread_mutex_lock(&info->mutex.print);
	if (info->stat.end == 0)
		printf("%ld %d %s\n", get_time() - info->birth_t, idx + 1, str);
	if (strstr(str, "is eating"))
	{
		philo->last_eat_t = get_time();
		if (++(philo->cnt_eat) == philo->info->arg.must_eat)
		{
			philo->info->stat.n_full++;
			if (philo->info->stat.n_full == philo->info->arg.n_philo)
				philo->info->stat.end++;
		}
	}
	pthread_mutex_unlock(&info->mutex.print);
}

void mutex_free(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_destroy(philo[i].left);
	pthread_mutex_destroy(&philo->info->mutex.print);
}
