/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/03/20 18:35:39 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_map_sqr(char *map, int len, int x, int *y)
{
	char	**line;
	int		i = 0;
	int		e = 0;
	char	*tmp;

	tmp = ft_strdup(map);
	tmp[len - 1] = '\0';
	line = ft_strsplit(ft_strrchr(tmp, '\n'), ' ');
	while (line[i++] != '\0')
		++x;
	tmp = ft_replace_char(tmp, '\n', '\0');
	i = 0;
	while (tmp[e] != '\0')
	{
		i = 0;
		line = ft_strsplit(tmp, ' ');
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

int		main(int argc, char **argv)
{
	t_l				info;
	char			*map;
	char			**pt;
	char			buf[BUFF_SIZE + 1];
	int				i;
	int				y = 1;
	int				*h;
	int				*x;
	int				cake;

	i = 0;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, X, Y, "Cake");
	if (!(info.fd = open(argv[1], O_RDONLY)))
			return (-1);
	info.rd = read(info.fd, buf, BUFF_SIZE);
	buf[info.rd] = '\0';
//	printf("fd = %i && rd = %i\n======BUF======\n|%s|\n", w.fd, w.rd, buf);
	info.width = ft_map_sqr(buf, info.rd, 0, &info.height); 
	map = ft_replace_char(buf, '\n', ' ');
//	printf("width = %i && height = %i\n=========BUF=======\n%s\n===========MAP=========\n%s\n", w.width, w.height, buf, map);
	pt = ft_strsplit(map, ' ');
	h = ft_array_int(pt, info.width * info.height + 1, 0, info.width);
	x = ft_array_int(pt, info.width * info.height + 1, 1, info.width);
	cake = info.height * info.width;
	while (i < cake && i < 9)
	{
	//	ft_isometrie(&x[i], &h[i] + y, &x[i + 1], &h[i + 1] + y);
		printf("I===>%i====Y===> %i && x => %i && h => %i\n", i, y, x[i], h[i]);
		ft_get_point(x[i], h[i], x[i + 1], h[i + 1], &info);
		if (++i % info.width == 0 && y < info.height)
			y++;
	}
	printf("MA BITE \n");
	mlx_put_image_to_window(info.mlx, info.win, info.img, X, Y);
/*	while (y > 0 && 0 <= i--)
	{
		ft_isometrie(&x[i - width], &h[i - width] + y - 1, &x[i], &h[i] + y);
		ft_get_point(x[i - 1], h[i - 1], x[i], h[i]);
		if (i % width == 0 && y < 0 )
			y--;
	}*/
	mlx_key_hook(info.win, ft_key, 0);
	mlx_loop(info.mlx);
	return (0);
}
