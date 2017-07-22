/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/21 16:59:09 by ltran            ###   ########.fr       */
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
/*
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
	exit(0);
	while (++z < pt->y + 1 && (y + 1) * t->zm <= 1400 && x <= 2560)
	{
		while (++y < pt->x - 1 && z < pt->y && (y + 1) * t->zm <= 1400 && x <= 2560)
			trace(z - buf[(y * pt->y) + z], y - buf[(y * pt->y) + z], z - buf[((y + 1) * pt->y) + z], (y + 1) - buf[((y + 1) * pt->y) + z], t);
		y = -1;
	}
}*/
// placement des variables correctement
void		trace_gril(t_coord *pt, t_tool *t, int *buf)
{
	int		y;
	int		x;

	y = -1;
	while (++y < pt->y + 1/* && (x + 1) * t->zm <= 2560*/)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y/* && (x + 1) * t->zm <= 2560*/)
			trace(x - buf[(y * pt->x) + x], y - buf[(y * pt->x) + x], (x + 1) - buf[(y * pt->x) + x + 1],
			y - buf[(y * pt->x) + x + 1], t);
	}
	x = -1;
	while (++x < pt->x + 1 /*&& (y + 1) * t->zm <= 1400*/)
	{
		y = -1;
		while (++y < pt->y - 1 && x < pt->x /*&& (y + 1) * t->zm <= 1400*/)
			trace(x - buf[(y * pt->x) + x], y - buf[(y * pt->x) + x], x - buf[((y + 1) * pt->x) + x],
			(y + 1) - buf[((y + 1) * pt->x) + x], t);
	} 
}

void		trace_gril(t_coord *pt, t_tool *t, int *buf)
{
	while ()
		trace();
	while ()
		trace();
}

t_xy	*add_x(int x, int y, int buf, t_xy *xy)
{
	t_xy	*new;

	new = NULL;
	new = (t_xy*)malloc(sizeof(t_xy));
	new->x = x - buf[(y * pt->x) + x];
	new->y = y - buf[(y * pt->x) + x];
	new->xx = (x + 1) - buf[(y * pt->x) + x + 1];
	new->yy = y - buf[(y * pt->x) + x + 1];
	new->next = x;
	return (new);
}

t_yx	*add_y(int x, int y, int buf, t_yx *yx)
{
	t_xy	*new;

	new = NULL;
	new = (t_yx*)malloc(sizeof(t_yx));
	new->x = x - buf[(y * pt->x) + x];
	new->y = y - buf[(y * pt->x) + x];
	new->xx = x - buf[((y + 1) * pt->x) + x];
	new->yy = (y + 1) - buf[((y + 1) * pt->x) + x]);
	new->next = y;
	return (new);
}

t_xy	*lst_xy(t_coord *pt, int *buf, t_xy *xy)
{
	int		y;
	int		x;

	y = -1;
	while (++y < pt->y + 1)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y)
		{
			xy = add_x(x, y, buf, xy);
			if (xy->xx > xmax)
				xmax = xy->xx;
			if (xy->yy > ymax)
				ymax = xy->yy;
			if (xy->xx < xmin)
				xmin = xy->xx;
			if (xy->yy < ymin)
				ymin = xy->yy;
		}
	}
	return (xy);
}

t_yx	*lst_yx(t_coord *pt, int *buf, t_xy *yx)
{
	int		y;
	int		x;

	x = -1;
	// declaration de la premiere variable pour les max et min et ZOOM
	while (++x < pt->x + 1)
	{
		y = -1;
		while (++y < pt->y - 1 && x < pt->x)
			yx = add_y(x, y, buf, yx);
	} 
	return (yx);
}

void		start_window(char **map, t_coord *pt, t_tool *t, int *buf)
{
	t_xy	*xy;
	t_yx	*yx;
	
	xy = lst_xy(pt, buf, NULL);
	yx = lst_yx(pt, buf, NULL);
	exit (0);
	t->zm = 5;
	t->dex = 450  + 650;
	t->dey = 352 + 216;
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
	printf("Mx %i || My %i || mx %i || my %i\nLongueur : %i && Largeur : %i\n", t->xmax, t->ymax, t->xmin, t->ymin, (t->xmax - t->xmin), (t->ymax - t->ymin));
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
	pt->y = i;
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
			pt->y = -1;
			return (pt);
		}
	}
	`pt->x = o;
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
	if (pt->y == -1)
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
