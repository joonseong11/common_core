/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:05:15 by jujeon            #+#    #+#             */
/*   Updated: 2022/05/22 19:26:50 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	char	*line;

	if (!(fd1 = open("./test1.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	printf("%d \n", fd1);
	while (NULL != (line = get_next_line(fd1)))
	{
		printf("main line : %s \n", line);
		///free(line);
	}
	close(fd1);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
