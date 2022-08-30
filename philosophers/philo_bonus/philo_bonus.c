/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:21:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/30 21:18:16 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	p_atoi(const char *str)
{
	long long	ret;

	ret = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			ret = ret * 10 + *str - '0';
			if (ret > INT_MAX || ret < INT_MIN)
				return (ERROR);
		}
		else
			return (ERROR);
		str++;
	}
	return (ret);
}

/*
	error cases are
	- input of must_eat is 0, negative, combine of characters or super big number
	- then p_atoi memo return -1
*/

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

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

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
	info->sema.print = sem_open("eat_checker", O_CREAT | O_EXCL, 0644, 0);
	if (info->sema.eat_checker == SEM_FAILED)
	{
		sem_unlink("eat_checker");
		info->sema.eat_checker = sem_open("eat_checker", O_CREAT | O_EXCL, \
			0644, 0);
	}
	return (SUCCESS);
}

//			O_EXCL          error if create and semaphore exists

int	init(int argc, char **argv, t_philo *philo, pid_t *pid)
{
	int	idx;

	memset(philo, 0, sizeof(t_philo));
	if (parse_arg(argc, argv, &philo->info) == ERROR)
		return (ERROR);
	init_philo(philo, &philo->info, &philo->info.arg);
	idx = 0;
	philo->info.birth_t = get_time();
	while (idx < philo->info.arg.n_philo)
	{
		pid[idx] = fork();
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (init(argc, argv, &philo))
		return (ERROR);
	return (0);
}
