/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:41:22 by ltran             #+#    #+#             */
/*   Updated: 2017/07/29 15:14:14 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	trace_yx(t_trace t, int y, t_coord *pt)
{
	int		i;
	int		dy;
	int		dx;

	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= y)
	{
		if (t.y1 > -1 && t.y1 < Y && t.x1 > -1 && t.x1 < X)
			pixel_put(t, rgb_to_hexa(pt), pt);
		++i;
		t.y1 += t.yinc;
		t.ey -= dx;
		if (t.ey < 0)
		{
			t.x1 += t.xinc;
			t.ey += dy;
		}
	}
}

void	trace_xy(t_trace t, int x, t_coord *pt)
{
	int		i;
	int		dy;
	int		dx;

	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= x)
	{
		if (t.x1 > -1 && t.x1 < X && t.y1 > -1 && t.y1 < Y)
			pixel_put(t, rgb_to_hexa(pt), pt);
		++i;
		t.x1 += t.xinc;
		t.ex -= dy;
		if (t.ex < 0)
		{
			t.y1 += t.yinc;
			t.ex += dx;
		}
	}
}

void	trace(t_xy *x, t_coord *pt)
{
	t_trace		t;

	t.x1 = pt->dex + (x->x - x->y);
	t.x2 = pt->dex + (x->xx - x->yy);
	t.y1 = pt->dey + ((x->y + x->x) / 2);
	t.y2 = pt->dey + ((x->yy + x->xx) / 2);
	t.ex = abs(t.x2 - t.x1);
	t.ey = abs(t.y2 - t.y1);
	t.xinc = t.x1 > t.x2 ? -1 : 1;
	t.yinc = t.y1 > t.y2 ? -1 : 1;
	if (t.ex > t.ey)
		trace_xy(t, t.ex, pt);
	else
		trace_yx(t, t.ey, pt);
}
