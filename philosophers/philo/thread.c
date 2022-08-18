/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:44:29 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/18 20:44:53 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int take_fork(t_philo *philo)
{
	int kill_;

	pthread_mutex_lock(&philo->info->mutex.print);
	kill_ = philo->info->stat.end;
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (kill_)
		return (ERROR);
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(philo->left);
		philo_print(philo, philo->info, philo->idx, "has taken a fork");
		pthread_mutex_lock(philo->right);
		philo_print(philo, philo->info, philo->idx, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right);
		philo_print(philo, philo->info, philo->idx, "has taken a fork");
		pthread_mutex_lock(philo->left);
		philo_print(philo, philo->info, philo->idx, "has taken a fork");
	}
	return (SUCCESS);
}

int eating(t_philo *philo, t_arg *arg)
{
	int kill_;

	pthread_mutex_lock(&philo->info->mutex.print);
	kill_ = philo->info->stat.end;
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (kill_)
		return (ERROR);
	philo_print(philo, philo->info, philo->idx, "is eating");
	smart_timer(arg->eat_time);
	return (SUCCESS);
}

int sleep_thinking(t_philo *philo, t_arg *arg)
{
	int kill_;

	pthread_mutex_lock(&philo->info->mutex.print);
	kill_ = philo->info->stat.end;
	pthread_mutex_unlock(&philo->info->mutex.print);

	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	if (kill_)
		return (ERROR);
	philo_print(philo, philo->info, philo->idx, "is sleeping");
	smart_timer(arg->sleep_time);
	philo_print(philo, philo->info, philo->idx, "is thinking");
	// usleep(10);
	return (SUCCESS);
}

void *action(void *param)
{
	t_philo *philo;
	philo = (t_philo *)param;

	pthread_mutex_lock(&philo->info->mutex.print);
	philo->last_eat_t = get_time();
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (philo->idx % 2 != 0)
		smart_timer(philo->info->arg.eat_time / 2);
	while (!take_fork(philo) && !eating(philo, &philo->info->arg) && !sleep_thinking(philo, &philo->info->arg))
		;
	return (NULL);
}
