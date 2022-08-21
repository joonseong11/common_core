/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:16:37 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/22 01:21:22 by jujeon           ###   ########seoul.kr  */
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
	smart_timer((*philo).info.arg.eat_time);
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

	t_philo	*const philo  = (t_philo *)param;
	
	while (1)
	{
		sem_wait(philo->info.sema.print);
		now_t = get_time();
		if (now_t > philo->info.arg.die_time + philo->last_eat_t)
		{
			printf("%lu %d died\n", now_t - (*philo).info.birth_t, philo->idx + 1);
			exit(1);
		}
		sem_post(philo->info.sema.print);
	}
	return (NULL);
}

void	action(t_philo philo)
{
	pthread_t	tid;

	tid = NULL;
	//pthread_create(&tid, NULL, monitor, &philo);
	// sem_wait(philo.info.sema.print);
	philo.last_eat_t = get_time();
	pthread_create(&tid, NULL, monitor, &philo);
	// sem_post(philo.info.sema.print);
	while (!take_fork(&philo)
			&& !eating(&philo)
			&& !sleep_thinking(&philo));
	exit(1);
}
