/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:16:32 by ltran             #+#    #+#             */
/*   Updated: 2017/02/25 09:46:36 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"
#include "mlx.h"
#include "stdio.h"

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_diagonal(int ex, int ey , int x1, int y1, void *mlx, void *win)
{
	int     i = 0;
	int		dx;
	int		dy;
	int		ix;
	int		iy;
	int		x = x1;
	int		y = 1000;

	ix = (ex > 0) ? -1 : 1;
	iy = (ey > 0) ? -1 : 1;
	printf("ix = %d || iy = %d\n",ix, iy);
	ex = abs(ex);
	ey = abs(ey);
	dx = 2*ex;
	dy = 2*ey;

	while (i <= ex)
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

int     main()
{
	int     x2 = 600;
	int     y2 = 999 - 0;
	int     x1 = 200;
	int     y1 = 999 - 799;

	int     ex = x2 - x1;
	int     ey = y2 - y1;
	//fct ex > ey
/*	int		ex = 400;
	int		ey = 200;*/
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "CAKE");
/*	if (ex > ey)
		ft_diagonal(ex, ey, x1, y1, mlx, win);
	else*/
	ft_diagonal(ey, ex, x1, y1, mlx, win);
	mlx_pixel_put(mlx, win, x2, y2, 0X00ffff00);
	mlx_pixel_put(mlx, win, x1, y1, 0X00ffff00);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return (0);
}
