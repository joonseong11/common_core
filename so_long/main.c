/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:41:50 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/15 16:21:42 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 42
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct s_img
{
	void	*coin;
	void	*hero;
	void	*tile;
	void	*wall;
	void	*door;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		wid;
	int		hei;
	char	*str_line;
	int		cnt;
}	t_game;

void	setting_img(t_game *game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			if (game->str_line[hei * game->wid + wid] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img->wall, wid*64, hei*64);
			else if (game->str_line[hei * game->wid + wid] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img->coin, wid * 64, hei * 64);
			else if (game->str_line[hei * game->wid + wid] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img->hero, wid * 64, hei * 64);
			else if (game->str_line[hei * game->wid + wid] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img->door, wid * 64, hei * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img->tile, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}

size_t g_strlen(const char *str)
{
	int i;

	i = 0;
	if (*str == 0)
		return (i);
	while (str[i] != 0)
		i++;
	return (i);
}

char *g_strdup(const char *s1)
{
	char *str;
	int len;
	int i;

	i = 0;
	len = g_strlen(s1);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *g_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;
	size_t ourlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	ourlen = g_strlen(s);
	if (start >= ourlen)
		return (g_strdup(""));
	if (ourlen - start < len)
		len = ourlen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char *g_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char *g_strjoin2(char const *s1, char const *s2, size_t len, char *str)
{
	size_t i;
	size_t j;
	size_t len_s1;

	i = 0;
	j = 0;
	len_s1 = g_strlen(s1);
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char *g_strjoin(char const *s1, char const *s2)
{
	size_t len;
	char *str;

	if (s1 == NULL)
		return (g_strdup(s2));
	if (s2 == NULL)
		return (g_strdup(s1));
	len = g_strlen(s1) + g_strlen(s2);
	str = malloc(sizeof(char) * (len) + 1);
	if (str == NULL)
		return (NULL);
	str = g_strjoin2(s1, s2, len, str);
	free((void *)s1);
	return (str);
}

char *leave_newtemp(char *temp)
{
	char *newtemp;
	size_t len_newtemp;

	if (g_strchr(temp, '\n') == 0)
		return (NULL);
	len_newtemp = g_strlen(temp) - (g_strchr(temp, '\n') - temp + 1);
	newtemp = g_substr(temp, (g_strchr(temp, '\n') - temp + 1), len_newtemp);
	if (newtemp == NULL || *newtemp == '\0')
	{
		free(temp);
		free(newtemp);
		return (NULL);
	}
	free(temp);
	return (newtemp);
}

char *line_truncate(char *temp)
{
	char *line;

	if (g_strchr(temp, '\n') == 0)
		return (temp);
	line = g_substr(temp, 0, (g_strchr(temp, '\n') - temp + 1));
	if (line == NULL)
		return (NULL);
	return (line);
}

char *read_buf(int fd, char *temp)
{
	ssize_t check;
	char *buf;

	check = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[0] = '\0';
	while (g_strchr(buf, '\n') == 0 && check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		if (check < 0)
		{
			free(buf);
			return (NULL);
		}
		if (check > 0)
			temp = g_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char *get_next_line(int fd)
{
	static char *temp;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = read_buf(fd, temp);
	if (temp == NULL)
		return (NULL);
	line = line_truncate(temp);
	temp = leave_newtemp(temp);
	return (line);
}

char *ft_strdup_without_newline(char *s)
{
	char *new_mem;
	int size;
	int i;

	new_mem = NULL;
	size = g_strlen(s);
	i = 0;
	new_mem = malloc(size + 1);
	if (!(new_mem))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new_mem[i] = s[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}

int ft_strlcpy_without_newline(char *dst, char *src, int len)
{
	int src_len;
	int i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char *ft_strjoin_without_newline(char *s1, char *s2)
{
	char *new_mem;
	size_t s1_len;
	size_t s2_len;

	new_mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_without_newline(s2));
	else if (s2 == NULL)
		return (ft_strdup_without_newline(s1));
	s1_len = g_strlen(s1);
	s2_len = g_strlen(s2);
	new_mem = malloc(s1_len + s2_len);
	if (!(new_mem))
		return (NULL);
	ft_strlcpy_without_newline(new_mem, s1, s1_len + 1);
	ft_strlcpy_without_newline(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_mem);
}

void	move_w(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < g_strlen(game->str_line))
	{
		if (game -> str_line[i] == 'P')
			break;
	}
	if (game -> str_line[i - game->wid] == 'C')
		game->cnt++;
	if (game -> str_line[i - game->wid] == 'E' && )
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = g_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game -> hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin_without_newline(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img1;
	void *img2;
	void *img3;
	void *img4;
	int		img_width;
	int		img_height;
	t_game	*game;
	t_img	*img;
	char *filename = "./map.ber";

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (0);
	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (0);
	map_read(filename, game);
	img_width = 64;
	img_height = 64;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	game->mlx = mlx;
	game->win = win;
	game->img = img;
	game->img->tile = mlx_xpm_file_to_image(mlx, "./images/resized_tile2.xpm", &img_width, &img_height);
	game->img->hero = mlx_xpm_file_to_image(mlx, "./images/resized_hero2.xpm", &img_width, &img_height);
	game->img->coin = mlx_xpm_file_to_image(mlx, "./images/resized_coin2.xpm", &img_width, &img_height);
	game->img->wall = mlx_xpm_file_to_image(mlx, "./images/resized_wall2.xpm", &img_width, &img_height);
	game->img->door = mlx_xpm_file_to_image(mlx, "./images/resized_door2.xpm", &img_width, &img_height);
	setting_img(game);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_loop(mlx);
	return (0);
}