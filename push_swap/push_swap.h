/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:34:31 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/06 16:39:57 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 	// you must remove it!!!!!!!!!!!!!!!!!

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
	struct s_node	*back;
}	t_node;

typedef struct s_info
{
	t_node	*stacka_top;
	t_node	*stacka_bot;
	t_node	*stackb_top;
	t_node	*stackb_bot;
}	t_info;

/*
* 							NODE FUNC								*
*/

t_node		*ft_nodenew(int data);
void		ft_nodedelone(t_node *lst);
void		ft_nodeadd_back(t_node **lst, t_node *new);
t_node		*ft_nodelast(t_node *lst);
int			ft_nodesize(t_node *lst);

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
*							MANDATORY								*
*/
void	init(int argc, char **argv, t_info *info);
void	make_stacks(t_info *info);
void	putintostacka(char **arr, t_info *info);
void	isnoint(char *str);

#endif