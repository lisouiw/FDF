/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:47:54 by ltran             #+#    #+#             */
/*   Updated: 2017/06/30 19:06:04 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace(int x1, int y1, int x2, int y2)
{
	int		ax = abs(x2 - x1);
	int		ay = abs(y2 - y1);
	int		x = 2 * ax;
	int		y = 2 * ay;
	int		i = 0;
	int		cx;
	int		cy;
	
	cx = x1 > x2 ? -1 : 1;
	cy = y1 > y2 ? -1 : 1;


	if(ax < ay)
	{
		l = ay;
		p = y1;
		ip = cy;
		d = x1;
		dp = cx;
		xp = ex;
		dx = ay;
		dy = ax;
	}
	else
	{
		l = ax;
		p = x1;
		ip = cx;
		d = y1;
		dp = cy;
		xp = ex;
		dx = ay;
		dy = ax;
	}
	while (i <= l)
	{
		pixel();
		++i;
		p += ip;
		xp -= dy;
		if (xp < 0)
		{
			d += dp;
			xp += dx;
		}
	}
}
