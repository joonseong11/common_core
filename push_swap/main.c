/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/04 10:41:32 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_error(int errcase)
{
	if (errcase == NOARG)
		;
	else if (errcase == NOINT || errcase == OUTOFINT || \
		errcase == OVERLAP)
		ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	isnoint(char *str)
{
	int	i;

	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' && *str > '9')
		get_error(NOINT);	
}

void	putintostacka(char **arr)
{
	int			i;
	long long	num;

	i = 0;
	while (arr[i])
	{
		isnoint(arr[i]);
		num = ft_atolong(arr[i]);
		if (num < -2147483648 || num > 2147483647)
			get_error(OUTOFINT);
		ft_lstadd_back(s, ft_lstnew(ft_lstcontentnew(num)););
		++i;
	}
	check_error(arr);
}

void	init(int argc, char **argv)
{
	int		i;
	char 	**arr;

	i = 1;
	if (argc < 2)
		get_error(NOARG);
	while (argv[i])
	{
		arr = ft_split(argv[i], " ");
		putintostacka(arr);
		++i;
	}
}

void	make_stacks2(t_stack *stack, char a_or_b)
{
	stack = ft_calloc(1, sizeof(t_stack));
	stack->whether_a_or_b = a_or_b;
	stack->bottom = NULL;
	stack->top = NULL;
	stack->size = 0;
}

void	make_stacks(t_stack *stack_a, t_stack *stack_b)
{
	make_stacks2(stack_a, 'a');
	make_stacks2(stack_b, 'b');
}

#include <stdio.h> // must remove it!!!!!!!!!!!!!!!!

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	make_stacks(stack_a, stack_b);
	init(argc, argv);
	// dosort();
	// printcmds();
	return (0);
}
