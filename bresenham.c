/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:47:54 by ltran             #+#    #+#             */
/*   Updated: 2017/07/05 16:34:07 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace(int x1, int y1, int x2, int y2, char *adr, int line)
{
	int		ex = abs(x2 - x1);
	int		ey = abs(y2 - y1);
	int		dx = 2 * ex;
	int		dy = 2 * ey;
	int		Dx = ex;
	int		Dy = ey;
	int		i = 0;
	int		xinc = x1 > x2 ? -1 : 1;
	int		yinc = y1 > y2 ? -1 : 1;

	if (Dx > Dy)
	{
		while (i <= Dx)
		{
			pixel_put(adr, x1, y1, 0X00e9f24f, line);
			++i;
			x1 += xinc;
			ex -= dy;
			if (ex < 0)
			{
				y1 = yinc;
				ex += dx;
			}
		}
	}
	else if (Dx <= Dy)
	{
		while (i <= Dy)
		{
			pixel_put(adr, x1, y1, 0X00e9f24f, line);
			++i;
			y1 += yinc;
			ey -= dx;
			if (ey < 0)
			{
				x1 = xinc;
				ey += dy;
			}
		}
	}
}
