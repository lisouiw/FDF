/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/26 18:19:03 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		((t_coord*)param)->dey -= 25;
	if (keycode == 123)
		((t_coord*)param)->dex -= 25;
	if (keycode == 124)
		((t_coord*)param)->dex += 25;
	if (keycode == 125)
		((t_coord*)param)->dey += 25;
	if (keycode == 69)
		((t_coord*)param)->zm += ((t_coord*)param)->s_zm;
	if (keycode == 78 && ((t_coord*)param)->zm - ((t_coord*)param)->s_zm > 1)
		((t_coord*)param)->zm -= ((t_coord*)param)->s_zm;
	mlx_destroy_image(((t_coord*)param)->mlx, ((t_coord*)param)->img);
	start_window((t_coord*)param);
	return (0);
}

void		pixel_put(t_trace t, int color, t_coord *pt)
{
	int		i;

	i = pt->line * t.y1 + t.x1 * 4;
	pt->adr[i] = color & 0XFF;
	pt->adr[++i] = color >> 8 & 0XFF;
	pt->adr[++i] = color >> 16 & 0XFF;
}

void		trace_gril(t_coord *pt, t_xy *xy, t_xy *yx)
{
	while (xy != NULL)
	{
		trace(xy, pt);
		xy = xy->next;
	}
	while (yx != NULL)
	{
		trace(yx, pt);
		yx = yx->next;
	}
}

t_xy		*add_y(int x, int y, t_xy *yx, t_coord *pt)
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

t_xy		*add_x(int x, int y, t_xy *xy, t_coord *pt)
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

void		giv_zoom(t_coord *pt, int y)
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
	pt->zm = 2560 / (2 * (pt->xmax - pt->xmin)) < 1400 / (2 * (pt->ymax - pt->ymin))
		? 2560 / (2 * (pt->xmax - pt->xmin)) : 1400 / (2 * (pt->ymax - pt->ymin));
	pt->s_zm = pt->zm > 10 ? 5 : 1;
}

t_xy		*lst_xy(t_coord *pt, t_xy *xy)
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
			if ((pt->xk = (xy->xx - xy->yy)) > pt->xmax)
				pt->xmax = pt->xk;
			if (pt->xk < pt->xmin)
				pt->xmin = pt->xk;
			if (pt->ymax < (pt->yk = (xy->xx + xy->yy) / 2))
				pt->ymax = pt->yk;
			if (pt->yk < pt->ymin)
				pt->ymin = pt->yk;
		}
	}
	return (xy);
}

t_xy		*lst_yx(t_coord *pt, t_xy *yx)
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

void		start_window(t_coord *pt)
{
	t_xy	*xy;
	t_xy	*yx;

	if (pt->zm == 0)
	{
		pt->mlx = mlx_init();
		giv_zoom(pt, -1);
		pt->win = mlx_new_window(pt->mlx, 2560, 1400, "Coffee");
		xy = lst_xy(pt, NULL);
		yx = lst_yx(pt, NULL);
		pt->dex = (-1 * pt->xmin) + (2560 - (pt->xmax - pt->xmin)) / 2;
		pt->dey = (-1 * pt->ymin) + (1400 - (pt->ymax - pt->ymin)) / 2;
	}
	else
	{
		xy = lst_xy(pt, NULL);
		yx = lst_yx(pt, NULL);
	}
	pt->img = mlx_new_image(pt->mlx, 2560, 1400);
	pt->adr = mlx_get_data_addr(pt->img, &(pt->bit), &(pt->line), &(pt->endian));
	trace_gril(pt, xy, yx);
	mlx_put_image_to_window(pt->mlx, pt->win, pt->img, 0, 0);
	mlx_hook(pt->win, 2, 3, ft_key, pt);
	mlx_loop(pt->mlx);
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

void		get_info_map(t_coord *pt, char *buf)
{
	char		**map;

	pt = (t_coord*)malloc(sizeof(t_coord));
	map = ft_strsplit(buf, '\n');
	pt->ln = map;
	pt = verif_map(pt->ln, pt, 0, 0);
	if (pt->y == -1)
		err(NULL, 1);
	else
	{
		pt->buf = strsplit_two(buf, ' ', '\n');
		pt->zm = 0;
		start_window(pt);
	}
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
	get_info_map(NULL, buf);
	return (0);
}
