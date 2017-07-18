/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:41:22 by ltran             #+#    #+#             */
/*   Updated: 2017/07/18 11:55:42 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	trace_yx(int x1, int y1, int ex, int ey, char *adr, int line, int xinc, int yinc, int y)
{
	int		i;
	int		dy;
	int		dx;

//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, ex, ey);
	dy = 2 * ey;
	dx = 2 * ex;
	i = 0;
	while (i <= y && y1 < 1400)
	{
		pixel_put(adr, x1, y1, 0X00F46269, line);
		++i;
		y1 += yinc;
		ey -= dx;
		if (ey < 0)
		{
			x1 += xinc;
			ey += dy;
		}
	}
}

void	trace_xy(int x1, int y1, int ex, int ey, char *adr, int line, int xinc, int yinc, int x)
{
	int		i;
	int		dy;
	int		dx;

//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, ex, ey);
	dy = 2 * ey;
	dx = 2 * ex;
	i = 0;
	while (i <= x && x1 < 2560)
	{
		pixel_put(adr, x1, y1, 0X00F46269, line);
		++i;
		x1 += xinc;
		ex -= dy;
		if (ex < 0)
		{
			y1 += yinc;
			ex += dx;
		}
	}
}

void	trace(int x, int y, int xx, int yy, char *adr, int line, int zm)
{
	int		dex = 900;
	int		dey = 80;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = dex + (x - y) * (zm);
	x2 = dex + (xx - yy) * (zm);
//	printf("->x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
	y1 = dey + (y + x) * (zm / 2);
	y2 = dey + (yy + xx) * (zm / 2);
//	printf("x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
	int		ex = abs(x2 - x1);
	int		ey = abs(y2 - y1);
	int		Dx = ex;
	int		Dy = ey;
	int		xinc = x1 > x2 ? -1 : 1;
	int		yinc = y1 > y2 ? -1 : 1;

	if (Dx > Dy)
		trace_xy(x1, y1, ex, ey, adr, line, xinc, yinc, ex);
	else
		trace_yx(x1, y1, ex, ey, adr, line, xinc, yinc, Dy);
}
