/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:34:31 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 15:10:01 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

/*
* 							ENUM								*
*/

enum e_errcase
{
	NOARG = 0,
	NOINT,
	OUTOFINT,
	OVERLAP,
	WRONGARG,
	NOSORTED,
	OTHER
};

/*
* 							STRUCTURE								*
*/

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_head
{
	t_node	*next;
}	t_head;

typedef struct s_info
{
	t_head	*stacka_top;
	t_head	*stacka_bot;
	t_head	*stackb_top;
	t_head	*stackb_bot;
	int		checkdeadcase;
}	t_info;

typedef struct s_abc
{
	int	a;
	int	b;
	int	c;
}	t_abc;

/*
* 							NODE FUNC								*
*/

t_node		*ft_nodenew(int data);
t_head		*ft_headnew(void);
void		ft_nodedelone(t_node *lst);
void		ft_nodeaddback(t_node **node, t_node *new);
t_node		*ft_nodelast(t_node *lst);
int			ft_nodesize(t_node *lst);
t_node		*ft_nodesearch(t_head *top, int size);

/*
*							BASIC FUNC								*
*/

size_t		ft_strlen(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
long long	ft_atolong(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_free_db_array(char **arr);

/*
*							ERROR FUNC								*
*/

void		get_error(int errcase);
void		check_overlap(t_head *head, int num);
void		check_outofint(long long num);
void		check_noint(char *str);
void		check_noarg(int argc);

/*
*							COMMAND FUNC								*
*/

int			sa(t_info *info);
int			sb(t_info *info);
int			ss(t_info *info);
int			pb(t_info *info);
int			pa(t_info *info);
int			ra(t_info *info);
int			rb(t_info *info);
int			rr(t_info *info);
int			rra(t_info *info);
int			rrb(t_info *info);
int			rrr(t_info *info);
void		p3_1(t_head *top, t_head *bot, t_node *obj);
void		p3_2(t_head *top, t_node *obj);
void		safe_s(t_info *info, char c);
void		safe_p(t_info *info, char c);
void		safe_r(t_info *info, char c);
void		safe_rr(t_info *info, char c);

/*
*							MANDATORY FUNC								*
*/

void		putintostacka(char **arr, t_info *info);
void		make_stacks(t_info *info);
void		init(int argc, char **argv, t_info *info);
void		do_sort(t_info *info);
void		do_hardsort(t_info *info, int size);
void		do_hardsort_two(t_info *info, char c);
void		do_hardsort_three(t_info *info, char c);
void		do_hardsort_four(t_info *info);
void		do_hardsort_five(t_info *info);
void		do_mainsort(t_info *info);
int			checkdeadcase(t_info *info, int size);
int			issorted(t_info *info);
void		sort_makesandclock(t_info *info, int i, int chunk, int size);
void		sort_usesandclock(t_info *info, int size);

/*
*							CHECKER									*
*/

void		get_stdin(t_info *info, char *line);
void		get_stdin2(t_info *info, char *line);
void		check_ok(t_info *info);

/*
*							TEST FUNC								*
*/

void		test_start(t_info *info);
void		test_curr_next(t_head *top, char c);
void		test_wholecurr_next(t_info *info);
void		test_indexcurr_next(t_info *info);
void		test_sa(t_info *info);
void		test_sb(t_info *info);
void		test_ss(t_info *info);
void		test_pa(t_info *info);
void		test_pb(t_info *info);
void		test_ra(t_info *info);
void		test_rb(t_info *info);
void		test_rr(t_info *info);
void		test_rra(t_info *info);
void		test_rrb(t_info *info);
void		test_rrr(t_info *info);

#endif