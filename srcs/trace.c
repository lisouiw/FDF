/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:41:22 by ltran             #+#    #+#             */
/*   Updated: 2017/07/18 18:46:01 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	trace_yx(t_trace t, t_tool *tl, int y)
{
	int		i;
	int		dy;
	int		dx;

	printf("->x1 = %i y1 = %i x2 = %i y2 = %i y = %i\n", t.x1, t.y1, t.ex, t.ey, y);
	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= y && t.y1 < 1400)
	{
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

	printf("->x1 = %i y1 = %i x2 = %i y2 = %i x = %i\n", t.x1, t.y1, t.ex, t.ey,x);
	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= x && t.x1 < 2560)
	{
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

void	trace(int x, int y, int xx, int yy, t_tool *tl)
{
	t_trace		t;
	int			dex;
	int			dey;

	dex = 0;
	dey = 0;
	t.x1 = dex + (x - y) * (tl->zm);
	t.x2 = dex + (xx - yy) * (tl->zm);
//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
	t.y1 = dey + (y + x) * (tl->zm / 2);
	t.y2 = dey + (yy + xx) * (tl->zm / 2);
//	printf("x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
	t.ex = abs(t.x2 - t.x1);
	t.ey = abs(t.y2 - t.y1);
	t.xinc = t.x1 > t.x2 ? -1 : 1;
	t.yinc = t.y1 > t.y2 ? -1 : 1;
	if (t.ex > t.ey)
		trace_xy(t, tl, t.ex);
	else
		trace_yx(t, tl, t.ey);
}
