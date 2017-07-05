/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/05 17:01:10 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	pixel_put(char *adr, int x, int y, int color, int line)
{
	int		i;

	i = line * y  + x * 4;
	adr[i] = color & 0XFF;
	adr[++i] = color >> 8 & 0XFF;
	adr[++i] = color >> 16 & 0XFF;
}

void	start_window(char **map)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		endian;
	int		bit;
	int		line;
	int		x = -1;
	int		y;
	int		z = -1;
	char	*adr;


	mlx = mlx_init ();
	win = mlx_new_window(mlx, 2560, 1400, "Coffee");
	img = mlx_new_image(mlx, 2560, 1400);
	adr = mlx_get_data_addr(img, &bit, &line, &endian);
	while (++z < 11)
	{
		y = z*30;
		while (++x < 19)
			trace(x*30, y, (x+1)*30, y ,adr, line);
		x = -1;
	}
	z = -1;
	while (++z < 19)
	{
		x = z*30;
		while (++y < 11)
			trace(x, y*30, x, (y+1)*30 ,adr, line);
		y = -1;
	}
/*	while (++x < 19)
	{
		while (++y < 12)
			mlx_pixel_put(mlx, win, x *50, y*50, 0X002ff24f);
		y = -1;
	}*/
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
}

int		verif_map(char **map)
{
	char	**nbr;
	int		i = 0;
	int		o = 0;
	int		tmp = 0;

	while (map[i] != NULL)
		++i;
	printf("i = %i\n",i);
	i = -1;
	while (map[++i])
	{
		o = 0;
		nbr = ft_strsplit(map[i], ' ');
		while (nbr[o] != NULL)
			++o;
		tmp = (tmp == 0) ? o : tmp;
		if (tmp != o)
		{
			printf("map invalide\n");
			return (-1);
		}
	}
	printf("o = %i\n",o);
	return (0);
}

int		get_info_map(int i, char *buf)
{
	char	**map;

	map = ft_strsplit(buf, '\n');
	verif_map(map);
	start_window(map);
	return (0);
}
int		main(int ac, char **av)
{
	int		op;
	int		rd;
	char	buf[BUFF_SIZE+1];

	if (ac != 2 || !(op = open (av[1], O_RDONLY)))
		return (0);
	rd = read(op, buf, BUFF_SIZE);
	buf[rd] = '\0';
	get_info_map(-1, buf);
	return (0);
}
