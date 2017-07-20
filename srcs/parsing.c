/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/20 19:54:37 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		printf("Fleche Haut\n");
	if (keycode == 124)
		printf("Fleche Droite\n");
	if (keycode == 123)
		printf("Fleche Gauche\n");
	if (keycode == 125)
		printf("Fleche Bas\n");
	if (keycode == 69)
		printf("PLUS\n");
	if (keycode == 78)
		printf("MOINS\n");
	return (0);
}

void		pixel_put(t_tool *tl, t_trace t, int color)
{
	int		i;

	i = tl->line * t.y1 + t.x1 * 4;
	tl->adr[i] = color & 0XFF;
	tl->adr[++i] = color >> 8 & 0XFF;
	tl->adr[++i] = color >> 16 & 0XFF;
}

void		trace_gril(t_coord *pt, t_tool *t, int *buf)
{
	int		y;
	int		z;
	int		x;
	char	**nbr;

	y = 0;
	z = -1;
	x = -1;
	while (++z < pt->x + 1 && (x + 1) * t->zm <= 2560 && y <= 1400)
	{
		while (++x < pt->y - 1 && z < pt->x && (x + 1) * t->zm <= 2560 && y <= 1400)
			trace(x - buf[(z * pt->y) + x], z - buf[(z * pt->y) + x], (x + 1) - buf[(z * pt->y) + x + 1], z - buf[(z * pt->y) + x + 1], t);
		printf("\n");
		x = -1;
	}
	z = -1;
	y = -1;
	while (++z < pt->y + 1 && (y + 1) * t->zm <= 1400 && x <= 2560)
	{
		while (++y < pt->x - 1 && z < pt->y && (y + 1) * t->zm <= 1400 && x <= 2560)
			trace(z - buf[(y * pt->y) + z], y - buf[(y * pt->y) + z], z - buf[((y + 1) * pt->y) + z], (y + 1) - buf[((y + 1) * pt->y) + z], t);
		y = -1;
	}
}

void		start_window(char **map, t_coord *pt, t_tool *t, int *buf)
{
	t->zm = 60;
	t->dex = 600;
	t->dey = 500;
	t->xmax = t->dex + ((0 - buf[0]) - (0 - buf[0])) * (t->zm);
	t->xmin = t->xmax;
	t->ymax = t->dey + ((0 - buf[0]) + (0 - buf[0])) * (t->zm/2);
	t->ymin = t->ymax;
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, 2560, 1400, "Coffee");
	t->img = mlx_new_image(t->mlx, 2560, 1400);
	t->adr = mlx_get_data_addr(t->img, &(t->bit), &(t->line), &(t->endian));
	trace_gril(pt, t, buf);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	printf("Mx %i || My %i || mx %i || my %i\n", t->xmax, t->ymax, t->xmin, t->ymin);
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
			pt->x = -1;
			return (pt);
		}
	}
	pt->y = o;
	return (pt);
}

void		get_info_map(int i, char *buf)
{
	char		**map;
	t_coord		*pt;
	t_tool		*t;

	pt = NULL;
	pt = (t_coord*)malloc(sizeof(t_coord));
	map = ft_strsplit(buf, '\n');
	pt->ln = map;
	pt = verif_map(pt->ln, pt, 0, 0);
	printf("x-> %i || y-> %i\n", pt->x, pt->y);
	if (pt->x == -1)
		err(NULL, 1);
	else if (!(t = (t_tool*)malloc(sizeof(t_tool))))
		err(NULL, 2);
	else
		start_window(map, pt, t, strsplit_two(buf, ' ', '\n'));
}

int			main(int ac, char **av)
{
	int		op;
	int		rd;
	char	buf[BUFF_SIZE + 1];

	if (ac != 2 || (op = open(av[1], O_RDONLY)) == -1)
		return (err(strerror(errno), 0));
	if ((rd = read(op, buf, BUFF_SIZE)) == -1)
		return (err(strerror(errno), 0));
	buf[rd] = '\0';
	get_info_map(-1, buf);
	return (0);
}
