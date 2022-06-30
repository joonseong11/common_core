/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:34:31 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/30 23:39:01 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*bottom;
	t_list	*top;
	int		size;
}	t_stack;

typedef struct s_stack_cover
{
	char	whether_a_or_b;
	t_stack	*stack;
}	t_stack_cover;

enum e_caseoferror
{
	NOARG = 0,
	NOINT,
	OUTOFINT,
	OVERLAP
};

void	*ft_calloc(size_t count, size_t size);
#endif