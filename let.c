/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:16:32 by ltran             #+#    #+#             */
/*   Updated: 2017/01/30 17:41:43 by ltran            ###   ########.fr       */
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

	printf("Entre dans fct\n\nex = %d && ey = %d\n", ex, ey);
	ix = (ex > 0) ? 1 : -1;
	iy = (ey > 0) ? 1 : -1;
	dx = 2*abs(ex);
	dy = 2*abs(ey);
	ex = abs(ex);
	int		x = ex;
	int		y = ey;
	printf("ix = %d || iy = %d\nex = %d || ey = %d || x1 = %i || dy = %i|| dx = %i\n",ix, iy, ex, ey, x1, dy, dx);
	//while (i <= dx && i <= x)
	while (i <= dy && i <= y)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0X00FFCCCC);
		i++;
		y1 += iy; 
		//x1 += ix;
		ey -= dx; 
		//ex -= dy;
		//if (ex < 0)
		if (ey < 0)
		{
			x1 += ix;
			//y1 += iy;
			ey += dy;
			//ex += dx;
		}
	}
}

int     main()
{
	int     x1 = 600;
	int     y1 = 200;
	int     x2 = 800;
	int     y2 = 900;

	int     ex = x2 - x1;
	int     ey = y2 - y1;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "CAKE");
	printf("ex = %d && ey = %d\n", ex, ey);
//	if (ex > ey)
	ft_diagonal(ex, ey, x1, y1, mlx, win);
	/*else
		ft_diagonal(ey, ex, x1, y1, mlx, win);
*/	mlx_pixel_put(mlx, win, x1, y1, 0X0000FFFF);
	mlx_pixel_put(mlx, win, x2, y2, 0X0000FFFF);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return (0);
}
