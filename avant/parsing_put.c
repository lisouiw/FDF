/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/04/30 01:26:11 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count(char *tmp, int *x, int *y)
{
	int		i;
	int		*nb;

	i = 0;
	printf("=============COUNT=============\n");
	while (tmp[i])
	{
		while (tmp[i] == ' ')
			i++;
		printf("X = %i === Y = %i\nTmp ==> %c\n",*x, *y, tmp[i++]);
		if (tmp[i] != ' ')
		{
			(*x)++;
			while (tmp[i] != ' ' || tmp[i] != '\n')
				i++;
			if (tmp[i] == '\n')
			{
				nb[*y] = *x;
				(*y)++;
				x = 0;
			}
			i++;
		}
	}
	while (nb[i] && nb[i + 1])
	{
		if (nb[i] != nb[i + 1])
			return (-1);
	}
	return (0);
}

/*int		ft_map_sqr(char *map, int len, int x, int *y)
{
	char	**line;
	int		i = 0;
	int		e = 0;
	char	*tmp;

	printf("X = %i && Y = %i\n", x, *y);
	if (ft_count(map, &x , &y) == -1)
		return (-1); //fonction pour pour non rectangle
	tmp = ft_strdup(map);
	tmp[len - 1] = '\0';
	line = ft_strsplit(ft_strrchr(tmp, '\n'), ' ');
	printf("X = %i && Y = %i\n", x, *y);
	tmp = ft_replace_char(tmp, '\n', '\0');
	i = 0;
	printf("X = %i Y = %i\n", x, *y);
	return (x);
}*/

char	*ft_replace_char(char *str, char c, char r)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(str);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			str[i] = r;
		i++;
	}
	return (str);
}

int		*ft_array_int(char **pt, int len, int x, int width)
{
	int		*ent;
	int		i;
	
	i = 0;
	if (!(ent = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	ent[len] = '\0';
	while (x == 0 && pt[i] != NULL)
	{
		ent[i] = ft_atoi(pt[i]);
		i++;
	}
	while (x == 1 && pt[i] != NULL)
	{
		ent[i] = (i % width) + 1;
		i++;
	}
	return (ent);
}
/*
int		ft_error(int msg)
{
	if (mgs == -1)
		write(1 ,"ce n'est pas une grille\n", 24);
	return (0);
}

int		ft_trace(t_l *info)
{
	int				cake;
	int				y = 1;
	int				i = 0;
	
	cake = info->height * info->width;
	while (i < cake - 1)
	{
		ft_isometrie(&x[i], &h[i] + y, &x[i + 1], &h[i + 1] + y);
//		ft_get_point(x[i] *10, h[i]*10, x[i + 1]*10, h[i + 1]*10, &info);
		ft_get_point(x[i]*30, h[i]*y*30, x[i + 1]*30, h[i + 1]*y*30, &info);
		if (++i % info->width == 0 && y < info->height)
			y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, X, Y);
	while (y > 0 && 0 <= i--)
	{
		ft_isometrie(&x[i - width], &h[i - width] + y - 1, &x[i], &h[i] + y);
		ft_get_point(x[i - 1], h[i - 1], x[i], h[i]);
		if (i % width == 0 && y < 0 )
			y--;
	}
}*/

int		ft_check(int argc, char **argv, t_l *info)
{
	int				*h;
	int				*x;
	char			*map;
	char			**pt;

	info->height = 0;
	info->width = 0;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, X, Y, "FDF");
	if (!(info->fd = open(argv[1], O_RDONLY)))
		return (-1);
	info->rd = read(info->fd, info->buf, BUFF_SIZE);
	info->buf[info->rd] = '\0';
	printf("=========Avant===========\nWidth = %i && Height = %i\n", info->width, info->height);
//	info->width = ft_map_sqr(info->buf, info->rd, 0, &info->height);
	ft_count(info->buf, &info->width, &info->height);
	printf("========Apres===========\nWidth = %i && Height = %i\n", info->width, info->height);
/*	map = ft_replace_char(info->buf, '\n', ' ');
	pt = ft_strsplit(map, ' ');
	h = ft_array_int(pt, info->width * info->height, 0, info->width);
	x = ft_array_int(pt, info->width * info->height, 1, info->width);
	*/return (0);
}

int		main(int argc, char **argv)
{
	t_l				info;

	if (ft_check(argc, argv, &info) == -1)
		return (-1);
	printf("MA BITE \n");
	//ft_trace(&info);
	mlx_key_hook(info.win, ft_key, 0);
	mlx_loop(info.mlx);
	return (0);
}
