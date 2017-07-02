/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/06/30 18:43:08 by ltran            ###   ########.fr       */
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

	i = line * y + x *4;
	adr[i] = color & 0XFF;
	adr[++i] = color >> 8 & 0XFF;
	adr[++i] = color >> 16;
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
	int		y = 0;
	char	*adr;


	mlx = mlx_init ();
	win = mlx_new_window(mlx, 2560, 1400, "Coffee");
	img = mlx_new_image(mlx, 2560, 1400);
	adr = mlx_get_data_addr(img, &bit, &line, &endian);
	while (++x < 1)
		pixel_put(adr, x, y, 0X002F4F4F, line);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
}

int		get_info_map(int i, char *buf)
{
	char	**map;

	map = ft_strsplit(buf, '\n');
	while (map[++i])
		printf("->%s\n", map[i]);
	start_window(map);
	return (0);
}

int		count_line(char *buf, int rd, int i, int a)
{
	while (buf[++a])
	{
		if (buf[a] == '\n')
			++i;
	}
	if (buf[rd-1] != '\n')
		++i;
	return (i);
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
