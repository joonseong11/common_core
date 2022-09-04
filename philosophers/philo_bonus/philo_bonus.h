/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:39:42 by jujeon            #+#    #+#             */
/*   Updated: 2022/09/03 19:45:03 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
/*
 *			memset									*
 */
# include <string.h>
/*
 *			printf									*
 */
# include <stdio.h>
/*
 *			malloc, free, exit							*
 */
# include <stdlib.h>
/*
 *			write, usleep							*
 */
# include <unistd.h>
/*
 *			gettimeofday							*
 */
# include <sys/time.h>
/*
 *			semaphore's external functions			*
 */
# include <semaphore.h>
/*
 *			pthread's external functions			*
 */
# include <pthread.h>
/*
 *			waitpid									*
 */
# include <sys/wait.h>
/*
 *			kill									*
 */
# include <signal.h>
# define INT_MAX			2147483647
# define INT_MIN			-2147483648

//						structres

typedef struct s_sem
{
	sem_t	*fork;
	sem_t	*print;
	sem_t	*eat_checker;	
}	t_sem;

typedef struct s_arg
{
	int		die_time;
	int		n_philo;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg		arg;
	t_sem		sema;
	size_t		birth_t;
	pid_t		*pid;
}	t_info;

typedef struct s_philo
{
	int		idx;
	t_info	info;
	size_t	last_eat_t;
	int		eat_cnt;
}	t_philo;

enum e_enum
{
	ERROR = -1,
	SUCCESS
};

//						functions

/*
 *			initializer part
 */
int			init(int argc, char **argv, t_philo *philo);
int			parse_arg(int argc, char **argv, t_info *info);
int			init_philo(t_philo *philo, t_info *info, t_arg *arg);
/*
 *			process part
 */
void		action(t_philo *philo);
void		*monitor(void *param);
int			take_fork(t_philo *philo);
int			eating(t_philo *philo);
int			sleep_thinking(t_philo *philo);
/*
*			util functions
*/
long long	p_atoi(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		philo_print(t_philo *philo, t_info *info, int idx, char *str);
void		smart_timer(size_t time);
size_t		get_time(void);
#endif