/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:41:22 by ltran             #+#    #+#             */
/*   Updated: 2017/07/18 15:52:16 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	trace_yx(t_trace t, char *adr, int line, int y)
{
	int		i;
	int		dy;
	int		dx;

	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", t.x1, t.y1, t.ex, t.ey);
	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= y && t.y1 < 1400)
	{
		pixel_put(adr, t.x1, t.y1, 0X00F46269, line);
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

void	trace_xy(t_trace t, char *adr, int line, int x)
{
	int		i;
	int		dy;
	int		dx;

	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", t.x1, t.y1, t.ex, t.ey);
	dy = 2 * t.ey;
	dx = 2 * t.ex;
	i = 0;
	while (i <= x && t.x1 < 2560)
	{
		pixel_put(adr, t.x1, t.y1, 0X00F46269, line);
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

void	trace(int x, int y, int xx, int yy, t_tool *tl, int zm)
{
	t_trace		t;
	int			dex;
	int			dey;

	dex = 900;
	dey = 80;
	t.x1 = dex + (x - y) * (zm);
	t.x2 = dex + (xx - yy) * (zm);
//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
	t.y1 = dey + (y + x) * (zm / 2);
	t.y2 = dey + (yy + xx) * (zm / 2);
//	printf("x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
	t.ex = abs(t.x2 - t.x1);
	t.ey = abs(t.y2 - t.y1);
	t.xinc = t.x1 > t.x2 ? -1 : 1;
	t.yinc = t.y1 > t.y2 ? -1 : 1;
	if (t.ex > t.ey)
		trace_xy(t, tl->adr, tl->line, t.ex);
	else
		trace_yx(t, tl->adr, tl->line, t.ey);
}
