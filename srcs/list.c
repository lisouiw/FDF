/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/27 17:51:03 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_xy	*add_y(int x, int y, t_xy *yx, t_coord *pt)
{
	t_xy	*new;

	new = NULL;
	new = (t_xy*)malloc(sizeof(t_xy));
	new->x = (x - (pt->buf[(y * pt->x) + x]) * pt->high) * (pt->zm);
	new->y = (y - (pt->buf[(y * pt->x) + x]) * pt->high) * (pt->zm);
	new->xx = (x - (pt->buf[((y + 1) * pt->x) + x]) * pt->high) * (pt->zm);
	new->yy = ((y + 1) - (pt->buf[((y + 1) * pt->x) + x] * pt->high))
		* (pt->zm);
	new->next = yx;
	return (new);
}

t_xy	*add_x(int x, int y, t_xy *xy, t_coord *pt)
{
	t_xy	*new;

	new = NULL;
	new = (t_xy*)malloc(sizeof(t_xy));
	new->x = (x - (pt->buf[(y * pt->x) + x]) * pt->high) * (pt->zm);
	new->y = (y - (pt->buf[(y * pt->x) + x]) * pt->high) * (pt->zm);
	new->xx = ((x + 1) - (pt->buf[(y * pt->x) + x + 1]) * pt->high) * (pt->zm);
	new->yy = (y - (pt->buf[(y * pt->x) + x + 1]) * pt->high) * (pt->zm);
	new->next = xy;
	return (new);
}

t_xy	*lst_xy(t_coord *pt, t_xy *xy)
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

t_xy	*lst_yx(t_coord *pt, t_xy *yx)
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
