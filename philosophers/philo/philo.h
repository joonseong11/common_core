/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:33:52 by jujeon            #+#    #+#             */
/*   Updated: 2022/08/22 13:20:47 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*
 *			memset									*
 */
# include <string.h>
/*
 *			printf									*
 */
# include <stdio.h>
/*
 *			malloc, free							*
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
 *			pthread's external functions			*
 */
# include <pthread.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

//						structres

typedef struct s_status
{
	int	end;
	int	n_full;
}	t_status;

typedef struct s_mutex
{
	pthread_mutex_t		print;
}	t_mutex;

typedef struct s_arg
{
	int		n_philo;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg		arg;
	t_mutex		mutex;
	t_status	stat;
	size_t		birth_t;
}	t_info;

typedef struct s_philo
{
	int					idx;
	pthread_t			tid;
	int					cnt_eat;
	size_t				last_eat_t;
	t_info				*info;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
}	t_philo;

enum e_enum
{
	ERROR = -1,
	SUCCESS
};

//						functions

/*
 *			parse functions
 */
int			parse_arg(int argc, char **argv, t_info *info);
/*
 *			monitor function
 */
void		monitor(t_philo *philo, t_info *info);
/*
 *			initializer functions
 */
int			init_info(t_philo **philo, t_info *info);
int			init_mutex(t_info *info, pthread_mutex_t **fork);
int			init_philo(t_philo **philo, t_info *info, t_arg *arg, \
				pthread_mutex_t *fork);
/*
 *			thread functions
*/
void		*action(void *param);
int			sleep_thinking(t_philo *philo, t_arg *arg);
int			eating(t_philo *philo, t_arg *arg);
int			take_fork(t_philo *philo);
void		philo_print(t_philo *philo, t_info *info, int idx, char *str);
/*
 *			util functions
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		smart_timer(size_t time);
size_t		get_time(void);
void		mutexde_free(t_philo *philo);
#endif