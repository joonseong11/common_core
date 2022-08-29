/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 01:21:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/29 20:58:25 by jujeon           ###   ########.fr       */
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

int	init(int argc, char **argv, t_philo **philo)
{
	*philo = malloc(sizeof(t_philo) * (*philo)->info.arg.n_philo);
	memset(*philo, 0, sizeof(t_philo));
	if (parse_arg(argc, argv, &(*philo)->info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (init(argc, argv, &philo))
		return (ERROR);
	return (0);
}
