/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:53:51 by ltran             #+#    #+#             */
/*   Updated: 2017/03/13 12:15:39 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Iso
 * */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

void	ft_trace(int x1, int x2, int y1, int y2, void *mlx, void *win);

void	ft_isometrie(int x, int y, void *mlx, void *win)
{
	int		ad = 500;
	int		tmpx = x;
	int		tmpy = y;

	x = (tmpx + tmpy) /2;
	y = (tmpx - tmpy) / 2;
	if (x < y && x < 0)
	{
		y = y + abs(x);
		x = 0;
	}
	else if (x > y && y < 0)
	{
		x = abs(y);
		y = 0;
	}
	printf("x = %i || y = %i\n", x , y);
	ft_trace(ad * x, (x + 1) * ad, y * ad, y * ad, mlx, win);

}
