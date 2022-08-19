/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:51:51 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/19 15:58:08 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	t_philo	*philo;

	if (parse_arg(argc, argv, &info) == ERROR)
		return (ERROR);
	if (init_info(&philo, &info) == SUCCESS)
		monitor(philo);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_unlock(philo[i].left);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_join(philo[i].tid, NULL);
	mutexde_free(philo);
	return (0);
}
