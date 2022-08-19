/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:12:35 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/19 16:26:07 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	p_atoi(const	char	*str)
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

int	parse_arg(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (ERROR);
	info->arg.n_philo = p_atoi(argv[1]);
	info->arg.die_time = p_atoi(argv[2]);
	info->arg.eat_time = p_atoi(argv[3]);
	info->arg.sleep_time = p_atoi(argv[4]);
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

/*
	> p_atoi memo <
	- when get negetive number
	- when get character
	- when get super big number
	return (-1) <----------------

	> must_eat memo <
	0 means no argument of 6
	when get -1 means error
	{
		error cases are
		- input of must_eat is 0 (need to add)
		- input of must_eat is negetive (p_atoi)
		- input of must_eat is combine of characters (p_atoi)
		- input of must_eat is super big number (p_atoi)
	}
*/
