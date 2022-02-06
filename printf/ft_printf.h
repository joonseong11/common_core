/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:48:56 by jujeon            #+#    #+#             */
/*   Updated: 2022/02/06 19:48:57 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_body(const char *format, va_list ap);
void	ft_parse(char c, va_list ap);
void	ft_printf_char(char c);
void	ft_putstr_fd(char *s, int fd);

#endif
