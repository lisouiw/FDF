/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/03/18 15:44:37 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_map_sqr(char *map, int len, int x, int *y)
{
	char	**line;
	int		i = 0;
	int		e = 0;

	map[len - 1] = '\0';
	line = ft_strsplit(ft_strrchr(map, '\n'), ' ');
	while (line[i++] != '\0')
		++x;
	map = ft_replace_char(map, '\n', '\0');
	i = 0;
	while (map[e] != '\0')
	{
		i = 0;
		line = ft_strsplit(map, ' ');
		while (line[i] != '\0')
			i++;
		if (i != x)
			return (-1);
		e += i + 1;
		++(*y);
	}
	return (x);
}

char	*ft_replace_char(char *str, char c, char r)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			str[i] = r;
		i++;
	}
	return (str);
}

int		*ft_array_int(char *pt, int len, int *x, int width)
{
	int		*ent;
	int		i;

	i = 0;
	if (!(ent = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	if (!(x = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	ent[len] = '\0';
	x[len] = '\0';
	while (ent[i])
	{
		ent[i] = ft_atoi(&pt[i]);
		x[i] = i % width;
		i++;
	}
	return (ent);
}

int		main(int argc, char **argv)
{
	t_l				w;
	char			*map;
	char			**pt;
	char			buf[BUFF_SIZE + 1];
	int				i = 0;
	int				y = 1;
	int				*h;
	int				*x;

	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 2800, 2000, "Cake");
	if (!(w.fd = open(argv[1], O_RDONLY)))
			return (-1);
	w.rd = read(w.fd, buf, BUFF_SIZE);
	buf[w.rd] = '\0';
	printf("fd = %i && rd = %i\n======BUF======\n|%s|\n", w.fd, w.rd, buf);
	w.width = ft_map_sqr(buf, w.rd, 0, &w.height); 
	printf("width = %i && height = %i\n", w.width, w.height);
	map = ft_replace_char(buf, '\n', ' ');
//	printf("width = %i && height = %i\n ===========MAP=========\n%s", w.width, w.height,map);
/*	pt = ft_strsplit(map, ' ');
	h = ft_array_int(*pt, width * height + 1, &(*x), width);
	while (h[i])
	{
		ft_isometrie(&x[i], &h[i] + y, &x[i + 1], &h[i + 1] + y);
		ft_get_point(x[i], h[i], x[i + 1], h[i + 1]);
		if (++i % width == 0 && y < height)
			y++;
	}
	while (y > 0 && 0 <= i--)
	{
		ft_isometrie(&x[i - width], &h[i - width] + y - 1, &x[i], &h[i] + y);
		ft_get_point(x[i - 1], h[i - 1], x[i], h[i]);
		if (i % width == 0 && y < 0 )
			y--;
	}*/
	mlx_key_hook(w.win, ft_key, 0);
	mlx_loop(w.mlx);
	return (0);
}
