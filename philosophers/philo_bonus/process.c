/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:19:35 by jujeon            #+#    #+#             */
/*   Updated: 2022/09/03 20:28:51 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	sleep_thinking(t_philo *philo)
{
	sem_post(philo->info.sema.fork);
	sem_post(philo->info.sema.fork);
	philo_print(philo, &philo->info, philo->idx, "is sleeping");
	smart_timer(philo->info.arg.sleep_time);
	philo_print(philo, &philo->info, philo->idx, "is thinking");
	return (SUCCESS);
}

int	eating(t_philo *philo)
{
	philo_print(philo, &philo->info, philo->idx, "is eating");
	smart_timer(philo->info.arg.eat_time);
	return (SUCCESS);
}

int	take_fork(t_philo *philo)
{
	sem_wait(philo->info.sema.fork);
	philo_print(philo, &philo->info, philo->idx, "has taken a fork");
	sem_wait(philo->info.sema.fork);
	philo_print(philo, &philo->info, philo->idx, "has taken a fork");
	return (SUCCESS);
}

void	*monitor(void *param)
{
	size_t	now_t;
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		sem_wait(philo->info.sema.print);
		now_t = get_time();
		if (now_t > philo->info.arg.die_time + philo->last_eat_t)
		{
			printf("%ld %d died\n", now_t - philo->info.birth_t, philo->idx + 1);
			exit(1);
		}
		sem_post(philo->info.sema.print);
	}
	return (NULL);
}

void	action(t_philo *philo)
{
	pthread_t	tid;

	tid = NULL;
	philo->last_eat_t = get_time();
	pthread_create(&tid, NULL, monitor, philo);
	while (!take_fork(philo) && !eating(philo) && !sleep_thinking(philo))
	{
		usleep(500);
	}
	exit(1);
}
