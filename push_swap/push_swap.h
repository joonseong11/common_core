/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:34:31 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 22:50:49 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // you must remove it!!!!!!!!!!!!!!!!!

/*
* 							ENUM								*
*/

enum e_yesorno
{
	NO = 0,
	YES = 1
};

enum e_errcase
{
	NOARG = 0,
	NOINT,
	OUTOFINT,
	OVERLAP,
	OTHER
};

/*
* 							STRUCTURE								*
*/

typedef struct s_node
{
	int				data;
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
}	t_info;

/*
* 							NODE FUNC								*
*/

t_node		*ft_nodenew(int data);
t_head		*ft_headnew(void);
void		ft_nodedelone(t_node *lst);
void		ft_nodeaddback(t_node **lst, t_node *new);
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
long long	ft_atolong(const	char	*str);

/*
*							ERROR FUNC								*
*/

void		get_error(int errcase); // you need to add ft_ !!!!!!!!!!!!!
void		check_overlap(t_head *head, int num);
void		check_outofint(int num);
void		check_noint(char *str);
void		check_noarg(int argc);

/*
*							COMMAND FUNC								*
*/

int			sa(t_info *info);
int			sb(t_info *info);
int			ss(t_info *info);
void		pb(t_info *info);
void		pa(t_info *info);
int			ra(t_info *info);
int			rb(t_info *info);
int			rr(t_info *info);
int			rra(t_info *info);
int			rrb(t_info *info);
int			rrr(t_info *info);
void		p3_1(t_head *top, t_head *bot, t_node *obj);
void		p3_2(t_head *top, t_head *bot, t_node *obj);

/*
*							MANDATORY FUNC								*
*/

void		putintostacka(char **arr, t_info *info);
void		make_stacks(t_info *info);
void		init(int argc, char **argv, t_info *info);

/*
 *							TEST FUNC								*
 */

void		test_start(t_info *info);
void		test_curr_next(t_head *top, char c);
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