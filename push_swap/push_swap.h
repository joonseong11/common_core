/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:34:31 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/01 03:01:59 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

enum e_caseoferror
{
	NOARG = 0,
	NOINT,
	OUTOFINT,
	OVERLAP
};
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	char	whether_a_or_b;
	t_list	*bottom;
	t_list	*top;
	int		size;
}	t_stack;

/*
* 				BASIC FUNC
*/
t_list	*ft_lstnew(void *content);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);

#endif