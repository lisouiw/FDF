/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/10 13:50:13 by ltran            ###   ########.fr       */
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

void	start_window(char **map, t_coord *pt, t_tool *t)
{
	int		x = -1;
	int		y = 0;
	int		z = -1;
	char	*adr;
	int		zm = 80;

	t->mlx = mlx_init ();
	t->win = mlx_new_window(t->mlx, 2560, 1400, "Coffee");
	t->img = mlx_new_image(t->mlx, 2560, 1400);
	adr = mlx_get_data_addr(t->img, &(t->bit), &(t->line), &(t->endian));
	while (++z < pt->x+1 && (x+1)*zm <= 2560 && y <= 1400)
	{
		y = z*zm;
		while (++x < pt->y && (x+1)*zm <= 2560 && y <= 1400)
			trace(x*zm, y, (x+1)*zm, y ,adr, t->line);
		x = -1;
	}
	z = -1;
	y = -1;
	while (++z < pt->y+1 && (y+1)*zm <= 1400 && x <= 2560)
	{
		x = z*zm;
		while (++y < pt->x && (y+1)*zm <= 1400 && x <= 2560)
			trace(x, y*zm, x, (y+1)*zm ,adr, t->line);
		y = -1;
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_key_hook(t->win, ft_key, 0);
	mlx_loop(t->mlx);
}

t_coord		*verif_map(char **map, t_coord *pt, int i, int o)
{
	char	**nbr;
	int		tmp;

	tmp = 0;
	while (map[i] != NULL)
		++i;
	pt->x = i;
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
			pt->x = -1;
			return (pt);
		}
	}
	pt->y = o;
	printf("o = %i\n",o);
	return (pt);
}

int		get_info_map(int i, char *buf)
{
	char		**map;
	t_coord		*pt;
	t_tool	*t;

	pt = NULL;
	pt = (t_coord*)malloc(sizeof(t_coord));
	map = ft_strsplit(buf, '\n');
	pt->ln = map;
	pt = verif_map(pt->ln, pt, 0, 0);
	printf("x-> %i || y-> %i\n", pt->x, pt->y);
	if (pt->x == -1)
		return (0);
	t = (t_tool*)malloc(sizeof(t_tool));
	start_window(map, pt, t);
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
