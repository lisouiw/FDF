/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/24 13:34:22 by ltran            ###   ########.fr       */
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
// 
// placement des variables correctement
/*
void		trace_gril(t_coord *pt, t_tool *t, int *buf)
{
	int		y;
	int		x;

	y = -1;
	while (++y < pt->y + 1 && (x + 1) * t->zm <= 2560)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y && (x + 1) * t->zm <= 2560)
			trace(x - buf[(y * pt->x) + x], y - buf[(y * pt->x) + x], (x + 1) - buf[(y * pt->x) + x + 1],
			y - buf[(y * pt->x) + x + 1], t);
	}
	x = -1;
	while (++x < pt->x + 1 && (y + 1) * t->zm <= 1400)
	{
		y = -1;
		while (++y < pt->y - 1 && x < pt->x && (y + 1) * t->zm <= 1400)
			trace(x - buf[(y * pt->x) + x], y - buf[(y * pt->x) + x], x - buf[((y + 1) * pt->x) + x],
			(y + 1) - buf[((y + 1) * pt->x) + x], t);
	} 
}
*/
void		trace_gril(t_coord *pt, t_tool *tl, t_xy *xy, t_xy *yx)
{
	while (xy != NULL)
	{
		trace(xy, tl);
		xy = xy->next;
	}
	while (yx != NULL)
	{
		trace(yx, tl);
		yx = yx->next;
	}
}

/*
t_xy	*add_x(int x, int y, int *buf, t_xy *xy, t_coord *pt)
{
	t_xy	*new;

	new = NULL;
	new = (t_xy*)malloc(sizeof(t_xy));
	new->x = x - buf[(y * pt->x) + x];
	new->y = y - buf[(y * pt->x) + x];
	new->xx = (x + 1) - buf[(y * pt->x) + x + 1];
	new->yy = y - buf[(y * pt->x) + x + 1];
	new->next = xy;
	return (new);
}*/
/*
t_xy	*lst_xy(t_coord *pt, t_xy *xy)
{
	int		y;
	int		x;

	y = -1;
	while (++y < pt->y + 1)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y)
			xy = add_x(x, y, buf, yx, pt);
	}
	pt->xmax = (0 - buf[0]) - (0 - buf[0]);
	pt->xmin = pt->xmax;
	pt->ymax = (0 - buf[0]) + (0 - buf[0]);
	pt->ymin = pt->ymax;
	return (yx);

}*/

t_xy	*add_y(int x, int y, t_xy *yx, t_coord *pt)
{
	t_xy	*new;

	new = NULL;
	new = (t_xy*)malloc(sizeof(t_xy));
	new->x = (x - pt->buf[(y * pt->x) + x]) * (pt->zm);
	new->y = (y - pt->buf[(y * pt->x) + x]) * (pt->zm);
	new->xx = (x - pt->buf[((y + 1) * pt->x) + x]) * (pt->zm);
	new->yy = ((y + 1) - pt->buf[((y + 1) * pt->x) + x]) * (pt->zm);
	new->next = yx;
	return (new);
}

t_xy	*add_x(int x, int y, t_xy *xy, t_coord *pt)
{
	t_xy	*new;
 
	new = NULL;
	new = (t_xy*)malloc(sizeof(t_xy));
	new->x = (x - pt->buf[(y * pt->x) + x]) * (pt->zm);
	new->y = (y - pt->buf[(y * pt->x) + x]) * (pt->zm);
	new->xx = ((x + 1) - pt->buf[(y * pt->x) + x + 1]) * (pt->zm);
	new->yy = (y - pt->buf[(y * pt->x) + x + 1]) * (pt->zm);
	new->next = xy;
	return (new);
}

void	giv_zoom(t_coord *pt, t_tool *tl, int y)
{
	int		x;

	pt->xmax = (0 - pt->buf[0]) - (0 - pt->buf[0]);
	pt->xmin = pt->xmax;
	pt->ymax = (0 - pt->buf[0]) + (0 - pt->buf[0]);
	pt->ymin = pt->ymax;
	while (++y < pt->y + 1)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y)
		{
			if ((pt->xk = (x + 1) - pt->buf[(y * pt->x) + x + 1]) > pt->xmax)
				pt->xmax = pt->xk;
			if ((pt->yk = y - pt->buf[(y * pt->x) + x + 1]) > pt->ymax)
				pt->ymax = pt->yk;
			if (pt->xk < pt->xmin)
				pt->xmin = pt->xk;
			if (pt->yk < pt->ymin)
				pt->ymin = pt->yk;
		}
	}
	pt->zm = 2560/(2*(pt->xmax - pt->xmin)) < 1400 /(2* (pt->ymax - pt->ymin))
		? 2560/(2*(pt->xmax - pt->xmin)) : 1400 /(2* (pt->ymax - pt->ymin));
}

t_xy	*lst_xy(t_coord *pt, t_tool *tl, t_xy *xy)
{
	int		y;
	int		x;

	y = -1;
	pt->xmax = ((0 - pt->buf[0]) - (0 - pt->buf[0])) * pt->zm;
	pt->xmin = pt->xmax;
	pt->ymax = ((0 - pt->buf[0]) + (0 - pt->buf[0])) * (pt->zm / 2);
	pt->ymin = pt->ymax;
	while (++y < pt->y + 1)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y)
		{
			xy = add_x(x, y, xy, pt);
			if((pt->xk = (xy->xx - xy->yy)) > pt->xmax)
				pt->xmax = pt->xk;
			if (pt->xk < pt->xmin)
				pt->xmin = pt->xk;
			if(pt->ymax < (pt->yk = (xy->xx + xy->yy) / 2))
				pt->ymax = pt->yk;
			if (pt->yk < pt->ymin)
				pt->ymin = pt->yk;
		}
	}
	return (xy);
}

t_xy	*lst_yx(t_coord *pt, t_tool *tl, t_xy *yx)
{
	int		y;
	int		x;

	x = -1;
	while (++x < pt->x + 1)
	{
		y = -1;
		while (++y < pt->y - 1 && x < pt->x)
			yx = add_y(x, y, yx, pt);
	}
	return (yx);
}

void		start_window(char **map, t_coord *pt, t_tool *tl, int *buf)
{
	t_xy	*xy;
	t_xy	*yx;

	pt->buf = buf;
	giv_zoom(pt, tl, -1);
	xy = lst_xy(pt, tl, NULL);
	yx = lst_yx(pt, tl, NULL);
	printf("=== xmax %i xmin %i ymax %i ymin %i ===\n", pt->xmax, pt->xmin, pt->ymax, pt->ymin);
	tl->dex = (-1 * pt->xmin) + (2560 - (pt->xmax - pt->xmin)) / 2;
	tl->dey = (-1 * pt->ymin) + (1400 - (pt->ymax - pt->ymin)) / 2;
	printf("dex = %i && dey %i\n", tl->dex, tl->dey);
	tl->mlx = mlx_init();
	tl->win = mlx_new_window(tl->mlx, 2560, 1400, "Coffee");
	tl->img = mlx_new_image(tl->mlx, 2560, 1400);
	tl->adr = mlx_get_data_addr(tl->img, &(tl->bit), &(tl->line), &(tl->endian));
	trace_gril(pt, tl, xy, yx);
	mlx_put_image_to_window(tl->mlx, tl->win, tl->img, 0, 0);
//	printf("Mx %i || My %i || mx %i || my %i\nLongueur : %i && Largeur : %i\n", t->xmax, t->ymax, t->xmin, t->ymin, (t->xmax - t->xmin), (t->ymax - t->ymin));
	mlx_key_hook(tl->win, ft_key, 0);
	mlx_loop(tl->mlx);
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
	pt->x = o;
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
