/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:47:54 by ltran             #+#    #+#             */
/*   Updated: 2017/07/17 13:54:22 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void pixel_put(char *adr, int x, int y, int color, int line)
{
	int		i;

	i = line * y + x * 4;
	adr[i] = color & 0XFF;
	adr[++i] = color >> 8 & 0XFF;
	adr[++i] = color >> 16 & 0XFF;
}

void	tra(int x, int y, int xx, int yy, char *adr, int line)
{
	int x1;
	int x2;
	int y1;
	int y2;


	int		zm = 1;
	int		dex = 100;
	int		dey = 200;
/*	x1 = (dex + x - y)*10;
	x2 = (dex + xx - yy) *10;
	y1 = (dey + x + y)*5;
	y2 = (dey + xx + yy) *5;
	*/
	x1 = (x)*zm;
	x2 = (xx) *zm;
	y1 = (y)*zm;
	y2 = (yy) *zm;
	
	int		ex = abs(x2 - x1);
	int		ey = abs(y2 - y1);
	int		dx = 2 * ex;
	int		dy = 2 * ey;
	int		Dx = ex;
	int		Dy = ey;
	int		i = 0;
	int		xinc = x1 > x2 ? -1 : 1;
	int		yinc = y1 > y2 ? -1 : 1;
	printf("x1 = %i y1 = %i x2 = %i y2 = %i\n", x1, y1, x2, y2);

	if (Dx > Dy)
	{
		while (i <= Dx && x1 < 2560)
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
	else
	{
		while (i <= Dy && y1 < 1400)
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
}


int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		endian;
	int		bit;
	int		line;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2560, 1400, "TEST");
	img = mlx_new_image(mlx, 2560, 1400);
	adr = mlx_get_data_addr(img, &bit, &line, &endian);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	tra(100,100,600, 800, adr, line);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return (0);
}











































