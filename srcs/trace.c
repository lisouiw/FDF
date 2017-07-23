/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:41:22 by ltran             #+#    #+#             */
/*   Updated: 2017/07/23 17:21:16 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	trace_yx(t_trace t, t_tool *tl, int y)
{
	int		i;
	int		dy;
	int		dx;

//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i y = %i\n", t.x1, t.y1, t.ex, t.ey, y);
	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= y)
	{
		if (t.y1 > -1 && t.y1 < 1400 && t.x1 > -1 && t.x1 < 2560)
			pixel_put(tl, t, 0X00F46269);
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

void	trace_xy(t_trace t, t_tool *tl, int x)
{
	int		i;
	int		dy;
	int		dx;

//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i x = %i\n", t.x1, t.y1, t.ex, t.ey,x);
	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= x)
	{
		if (t.x1 > -1 && t.x1 < 2560 && t.y1 > -1 && t.y1 < 1400)
			pixel_put(tl, t, 0X00F46269);
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

void	trace(t_xy *x, t_tool *tl)
//void	trace(int x, int y, int xx, int yy, t_tool *tl)
{
//	printf("->X = %i\n", x);
	t_trace		t;
	t.x1 = tl->dex + (x->x - x->y) * (tl->zm);
	t.x2 = tl->dex + (x->xx - x->yy) * (tl->zm);
	t.y1 = tl->dey + (x->y + x->x) * (tl->zm / 2);
	t.y2 = tl->dey + (x->yy + x->xx) * (tl->zm / 2);
	if (t.x2 > tl->xmax)
		tl->xmax = t.x2;
	if (t.y2 > tl->ymax)
		tl->ymax = t.y2;
	if (t.x2 < tl->xmin)
		tl->xmin = t.x2;
	if (t.y2 < tl->ymin)
		tl->ymin = t.y2;
	printf("x1 = %i y1 = %i x2 = %i y2 = %i\n", t.x1, t.y1, t.x2, t.y2);
	t.ex = abs(t.x2 - t.x1);
	t.ey = abs(t.y2 - t.y1);
	t.xinc = t.x1 > t.x2 ? -1 : 1;
	t.yinc = t.y1 > t.y2 ? -1 : 1;
	if (t.ex > t.ey)
		trace_xy(t, tl, t.ex);
	else
		trace_yx(t, tl, t.ey);
}
