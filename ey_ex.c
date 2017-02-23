/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:16:32 by ltran             #+#    #+#             */
/*   Updated: 2017/02/23 16:06:51 by ltran            ###   ########.fr       */
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

void	ft_diagonal(int ex, int ey , int x1, int y1, void *mlx, void *win)
{
	int     i = 0;
	int		ix;
	int		iy;
	int		dx;
	int		dy;

	ix = (ex > 0) ? -1 : 1;
	iy = (ey > 0) ? -1 : 1;
	dx = 2*abs(ex);
	dy = 2*abs(ey);
	ex = abs(ex);
	while (i <= ey)
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

int     main()
{
	int     x2 = 1000;
	int     y2 = 200;
	int     x1 = 800;
	int     y1 = 900;

	int     ex = x2 - x1;
	int     ey = y2 - y1;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "CAKE");
	printf("ex = %d && ey = %d\n", ex, ey);
	if (ex > ey)
	ft_diagonal(ex, ey, x1, y1, mlx, win);
	else
		ft_diagonal(ey, ex, x1, y1, mlx, win);
	mlx_pixel_put(mlx, win, x1, y1, 0X0000FFFF);
	mlx_pixel_put(mlx, win, x2, y2, 0X0000FFFF);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return (0);
}
