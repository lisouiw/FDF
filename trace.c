/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:41:22 by ltran             #+#    #+#             */
/*   Updated: 2017/07/11 16:55:44 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_yx(int x1, int y1, int ex, int ey, char *adr, int line, int xinc, int yinc, int Dy)
{
	int		i;
	int		dy;
	int		dx;

	dy = 2 * ey;
	dx = 2 * ex;
	i = 0;
	while (i <= Dy && y1 < 1400)
	{
		pixel_put(adr, x1, y1, 0X00e9f24f, line);
		++i;
		y1 += yinc;
		ey -= dx;
		//		printf("Y1 = %i && ey = %i\n",y1, ey);
		if (ey < 0)
		{
			x1 += xinc;
			ey += dy;
		}
	}
}

void	trace_xy(int x1, int y1, int ex, int ey, char *adr, int line, int xinc, int yinc, int Dx)
{
	int		i;
	int		dy = 2 * ey;
	int		dx = 2 * ex;

	dy = 2 * ey;
	dx = 2 * ex;
	i = 0;
	while (i <= Dx && x1 < 2560)
	{
		pixel_put(adr, x1, y1, 0X00e9f24f, line);
		++i;
		x1 += xinc;
		ex -= dy;
		//		printf("X1 = %i && ex = %i\n",x1, ex);
		if (ex < 0)
		{
			y1 += yinc;
			ex += dx;
		}
	}
}

void	trace(int x1, int y1, int x2, int y2, char *adr, int line)
{
	int		dex = 1000;
	int		dey = -200;

	x1 = dex + (x1 - y1) / 2;
	x2 = dex + (x2 - y2) / 2;
	y1 = dey + (x1 + y1) / 2;
	y2 = dey + (x2 + y2) / 2;
	printf("x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);
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
