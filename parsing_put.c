/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/03/13 17:58:49 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *Declaration du bordel
 * */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

int		ft_map_sqr(char *map, int len, int *x, int *y)
{
	char	**line;

	map[len - 1] = '\0';
	line = ft_strsplit(ft_strrchr(map, '\n'), ' ');
	while (line[i] != '\0')
		*(++x);
	line = ft_strsplit(map, '\n');
	while (*line[y] != '\0')
	{
		if (ft_strlen(*ft_strsplit(*line[y], ' ')) != x)
			return (-1);
		*++y;
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

int		main(int argc, char **argv)
{
	t_l				w;
	unsigned int	fd;
	int				rd;
	size_t			height;
	int				width;
	char			*map;
	char			**pt;
	char			buf[BUFF_SIZE + 1];
	int				i = 0;

	int				x2;
	int				y2;
	int				x1;
	int				y1;
	int				y = 1;

	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 2800, 2000, "Cake");
	if (!(fd = open(argv[1], O_RDONLY)))
			return (-1);
	rd = read(fd, buf, BUFF_SIZE);
	width = ft_map_sqr(buf, rd, 1, &height); 
	map = ft_replace_char(buf, '\n', ' ');
	pt = ft_strsplit(map, ' ');
	while (pt[i])
	{
		y1 = ft_atoi(pt[i]);
		y2 = ft_atoi(pt[i + 1]);
		ft_isometrie(&x1, &y1 + y, &x2 + 1, &y2 + y);
		ft_get_point(x1, y1, x2, y2);
		if (i % x == 0)
		{
			y++;
			x1 = 0;
		}
		i++;
		x1++;
	}
	mlx_key_hook(w.win, ft_key, 0);
	mlx_loop(w.mlx);
	return (0);
}
