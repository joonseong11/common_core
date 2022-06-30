/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/01 03:12:56 by jujeon           ###   ########seoul.kr  */
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

void	check_error(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] < 48 && 57 < arr[i][j])
			get_error(NOINT);
		++i;
	}
}

void	init(int argc, char**argv)
{
	int		i;
	int		j;
	char 	**arr;

	i = 1;
	j = 0;
	if (argc < 2)
		get_error(NOARG);
	else if (argc == 2)
	{
		arr = ft_split(argv[1], " ");
		check_error(arr);
	}
	else
	{
		while (argv[i][j])
		{
			j = 0;
		}
	}
}

void	make_stacks(t_stack *stack, char a_or_b)
{
	stack = ft_calloc(1, sizeof(t_stack));
	stack->whether_a_or_b = a_or_b;
	stack->bottom = NULL;
	stack->top = NULL;
	stack->size = 0;
}

#include <stdio.h> // must remove it!!!!!!!!!!!!!!!!

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int 	*a;
	int		*b;
	int		c;
	int		d;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	make_stacks(stack_a, 'a');
	make_stacks(stack_b, 'b');
	a = malloc(sizeof(int *));
	b = malloc(sizeof(int *));
	c = 10;
	d = 20;
	a = &c;
	b = &d;
	stack_a->bottom = ft_lstnew(a);
	ft_lstadd_back(&(stack_a->bottom), ft_lstnew(b));
	t_list *curr = stack_a->bottom;
	while (curr)
	{
		int *print = curr->content;
		printf("%d\n", *print);
		curr = curr->next;
	}
	//init(argc, argv);
	return (0);
}
