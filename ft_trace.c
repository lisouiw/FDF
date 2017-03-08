/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:16:32 by ltran             #+#    #+#             */
/*   Updated: 2017/03/05 13:31:35 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "mlx.h"
#include "stdio.h"

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_diagonal_ey(int ex, int ey , int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int     i = 0;
	int		dx;
	int		dy;
	int		ix = 1;
	int		iy = 1;
	int		m = ex;
	int		n = ey;
	if (x1 > x2)
		ix = -1;
	if (y1 > y2)
		iy = -1;
	dx = 2*ex;
	dy = 2*ey;
	printf("i = %i || ex = %i || ey = %i || y1 = %i || x1 = %i || x2 = %i || ix = %i || iy = %i || dy = %i ||dx = %i\n", i, ex, ey, y1, x1, x2, ix, iy, dy, dx);
	while (i <= n)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0X00FFCCCC);
		i++;
		y1 += iy;
		ey -= dx;
		if (ey < 0)
		{
			x1 += ix;
			ey += dy;
		}
	}
}

void	ft_diagonal_ex(int ex, int ey , int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int     i = 0;
	int		dx;
	int		dy;
	int		ix = 1;
	int		iy = 1;
	int		m = ex;
	int		n = ey;
	dx = 2*ex;
	dy = 2*ey;
	if (x1 > x2)
		ix = -1;
	if (y1 > y2)
		iy = -1;
	printf(" EX : i = %i || ex = %i || ey = %i || y1 = %i || y2 = %i || x1 = %i || x2 = %i || ix = %i || iy = %i || dy = %i ||dx = %i\n", i, ex, ey, y1, y2, x1, x2, ix, iy, dy, dx);
	while (i <= m)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0X00FFCCCC);
		i++;
		x1 += ix;
		ex -= dy;
		if (ex < 0)
		{
			y1 += iy;
			ex += dx;
		}
	}
}

void     ft_trace(int x1, int x2, int y1, int y2, void *mlx, void *win)
{
	int     ex = abs(x2 - x1);
	int     ey = abs(y2 - y1);

	if (ey > ex)
		ft_diagonal_ey(ex, ey, x1, y1, x2, y2, mlx, win);
	else
		ft_diagonal_ex(ex, ey, x1, y1, x2, y2, mlx, win);
	mlx_pixel_put(mlx, win, x1, y1, 0X0000FFFF);
	mlx_pixel_put(mlx, win, x2, y2, 0X0000FFFF);
}
