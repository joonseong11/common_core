/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:15:24 by jujeon            #+#    #+#             */
/*   Updated: 2022/09/03 20:28:43 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo(t_philo *philo, t_info *info, t_arg *arg)
{
	philo->last_eat_t = get_time();
	info->sema.fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644, \
		arg->n_philo);
	if (info->sema.fork == SEM_FAILED)
	{
		sem_unlink("sem_fork");
		info->sema.fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644, \
			arg->n_philo);
	}
	info->sema.print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (info->sema.print == SEM_FAILED)
	{
		sem_unlink("sem_print");
		info->sema.print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	}
	info->sema.eat_checker = sem_open("eat_checker", O_CREAT | O_EXCL, 0644, 0);
	if (info->sema.eat_checker == SEM_FAILED)
	{
		sem_unlink("eat_checker");
		info->sema.eat_checker = sem_open("eat_checker", O_CREAT | O_EXCL, \
			0644, 0);
	}
	return (SUCCESS);
}

int	parse_arg(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (ERROR);
	info->arg.n_philo = atoi(argv[1]);
	info->arg.die_time = atoi(argv[2]);
	info->arg.eat_time = atoi(argv[3]);
	info->arg.sleep_time = atoi(argv[4]);
	if (argc == 6)
	{
		info->arg.must_eat = p_atoi(argv[5]);
		if (info->arg.must_eat == 0)
			info->arg.must_eat = -1;
	}
	else
		info->arg.must_eat = 0;
	if (info->arg.n_philo <= 0 || info->arg.die_time <= 0
		|| info->arg.eat_time < 0 || info->arg.sleep_time < 0
		|| info->arg.must_eat < 0)
		return (ERROR);
	return (SUCCESS);
}

int	init(int argc, char **argv, t_philo *philo)
{
	int	idx;

	memset(philo, 0, sizeof(t_philo));
	if (parse_arg(argc, argv, &philo->info) == ERROR)
		return (ERROR);
	init_philo(philo, &philo->info, &philo->info.arg);
	philo->info.pid = malloc(sizeof(pid_t) * philo->info.arg.n_philo);
	if (philo->info.pid == NULL)
		return (ERROR);
	idx = 0;
	philo->info.birth_t = get_time();
	while (idx < philo->info.arg.n_philo)
	{
		philo->info.pid[idx] = fork();
		if (philo->info.pid[idx] == 0)
			action(philo);
		philo->idx = ++idx;
	}
	return (SUCCESS);
}
