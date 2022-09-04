/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:21:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/09/03 19:39:16 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_process(t_philo *philo)
{
	int	idx;

	idx = -1;
	waitpid(-1, 0, 0);
	while (++idx < philo->info.arg.n_philo)
	{
		kill(philo->info.pid[idx], SIGKILL);
	}
	sem_close(philo->info.sema.fork);
	sem_close(philo->info.sema.print);
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	while (idx--)
		waitpid(-1, 0, 0);
}

void	*eat_checker(void *param)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)param;
	i = -1;
	while (++i < philo->info.arg.n_philo)
	{
		sem_wait(philo->info.sema.eat_checker);
		if (i + 1 == philo->info.arg.n_philo)
			break ;
		sem_post(philo->info.sema.print);
	}
	i = -1;
	while (++i < philo->info.arg.n_philo)
		kill(philo->info.pid[i], SIGKILL);
	sem_close(philo->info.sema.eat_checker);
	sem_unlink("eat_checker");
	return (NULL);
}

void	checker_thread(int argc, t_philo *philo)
{
	pthread_t	tid_eatchecker;

	if (argc == 6)
	{
		pthread_create(&tid_eatchecker, NULL, eat_checker, philo);
		pthread_detach(tid_eatchecker);
	}
}

int	main(int argc, char **argv)
{
	t_philo		philo;

	if (init(argc, argv, &philo))
		return (ERROR);
	checker_thread(argc, &philo);
	end_process(&philo);
	return (0);
}
