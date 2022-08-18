/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:42:17 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/18 20:42:39 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo(t_philo **philo, t_info *info, t_arg *arg, pthread_mutex_t *fork)
{
	int i;

	i = 0;
	(*philo) = malloc(sizeof(t_philo) * arg->n_philo);
	if (*philo == NULL)
		return (ERROR);
	while (i < arg->n_philo)
	{
		(*philo)[i].idx = i;
		(*philo)[i].cnt_eat = 0;
		(*philo)[i].info = info;
		(*philo)[i].left = &fork[i];
		(*philo)[i].right = &fork[(i + 1) % arg->n_philo];
		(*philo)[i].last_eat_t = get_time();
		// philo[i].life_time = 0;
		++i;
	}
	i = -1;
	pthread_mutex_lock(&info->mutex.print);
	while (++i < arg->n_philo)
		if (pthread_create(&(*philo)[i].tid, NULL, action, &(*philo)[i]))
			return (ERROR);
	info->birth_t = get_time();
	pthread_mutex_unlock(&info->mutex.print);
	return (SUCCESS);
}

int init_mutex(t_info *info, pthread_mutex_t **fork)
{
	int i;

	*fork = malloc(sizeof(pthread_mutex_t) * info->arg.n_philo);
	if (!(*fork))
		return (ERROR);
	i = 0;
	while (i < info->arg.n_philo)
		if (pthread_mutex_init(&(*fork)[i++], PTHREAD_MUTEX_NORMAL) != 0)
			return (ERROR);
	if (pthread_mutex_init(&info->mutex.print, PTHREAD_MUTEX_NORMAL) != 0)
		return (ERROR);
	return (SUCCESS);
}

int init_info(t_philo **philo, t_info *info)
{
	pthread_mutex_t *fork;

	info->stat.end = 0;
	info->stat.n_full = 0;
	if (init_mutex(info, &fork) == ERROR)
		return (ERROR);
	if (init_philo(philo, info, &info->arg, fork) == ERROR)
		return (ERROR);
	return (SUCCESS);
}