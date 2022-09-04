/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:44:29 by jujeon            #+#    #+#             */
/*   Updated: 2022/09/03 20:35:52 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, t_info *info, int idx, char *str)
{
	pthread_mutex_lock(&info->mutex.print);
	if (info->stat.end == 0)
		printf("%ld %d %s\n", get_time() - info->birth_t, idx + 1, str);
	if (ft_strnstr(str, "is eating", 9))
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

int	sleep_thinking(t_philo *philo, t_arg *arg)
{
	int	kill_flag;

	pthread_mutex_lock(&philo->info->mutex.print);
	kill_flag = philo->info->stat.end;
	pthread_mutex_unlock(&philo->info->mutex.print);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	if (kill_flag)
		return (ERROR);
	philo_print(philo, philo->info, philo->idx, "is sleeping");
	smart_timer(arg->sleep_time);
	philo_print(philo, philo->info, philo->idx, "is thinking");
	return (SUCCESS);
}

int	eating(t_philo *philo, t_arg *arg)
{
	int	kill_flag;

	pthread_mutex_lock(&philo->info->mutex.print);
	kill_flag = philo->info->stat.end;
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (kill_flag)
		return (ERROR);
	philo_print(philo, philo->info, philo->idx, "is eating");
	smart_timer(arg->eat_time);
	return (SUCCESS);
}

int	take_fork(t_philo *philo)
{
	int	kill_flag;

	pthread_mutex_lock(&philo->info->mutex.print);
	kill_flag = philo->info->stat.end;
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (kill_flag)
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

void	*action(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->info->mutex.print);
	philo->last_eat_t = get_time();
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (philo->idx % 2 != 0)
		smart_timer(philo->info->arg.eat_time / 2);
	while (!take_fork(philo)
		&& !eating(philo, &philo->info->arg)
		&& !sleep_thinking(philo, &philo->info->arg))
		;
	return (NULL);
}
