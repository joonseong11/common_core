/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/30 23:45:38 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_error(int caseoferror)
{
	if (caseoferror == NOARG)
		;
	else if (caseoferror == NOINT)
		;
	else if (caseoferror == OUTOFINT)
		;
	else if (caseoferror == OVERLAP)
		;
	exit(EXIT_FAILURE);
}

void	init(int argc, char**argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		get_error(NOARG);
	while (argv[i][j])
	{
		j = 0;
	}
}

t_stack	*make_stacks2(void)
{
	t_stack	*tmp;

	tmp = ft_calloc(1, sizeof(t_stack));
	if (tmp != NULL)
	{
		tmp->bottom = NULL;
		tmp -> top = NULL;
		tmp -> size = 0;
	}
	return (tmp);
}

void	make_stacks(void)
{
	t_stack_cover	*stack_a;
	t_stack_cover	*stack_b;
	t_stack			tmp;

	stack_a = ft_calloc(1, sizeof(t_stack_cover));
	stack_b = ft_calloc(1, sizeof(t_stack_cover));
	stack_a->whether_a_or_b = 'a';
	stack_b->whether_a_or_b = 'b';
	stack_a->stack = make_stacks2();
	stack_b->stack = make_stacks2();
}

int	main(int argc, char **argv)
{
	make_stacks();
	init(argc, argv);
}
