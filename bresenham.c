/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:47:54 by ltran             #+#    #+#             */
/*   Updated: 2017/07/06 02:26:34 by ltran            ###   ########.fr       */
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
		while (i <= Dx && x1 != 2560)
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
	if (Dx < Dy)
	{
		while (i <= Dy && y1 != 1400)
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
}
