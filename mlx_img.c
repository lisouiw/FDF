/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:47:20 by ltran             #+#    #+#             */
/*   Updated: 2017/03/20 18:35:35 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_l *info, int x, int y, int color)
{
	int i;

	i = info->size * y + x * 4;
//	printf("i = %i && size = %i\n", i, info->size);
	info->addr[i] = color & 0XFF;
	info->addr[++i] = color >> 8 & 0XFF;
	info->addr[++i] = color >> 16 & 0XFF;
}

/*int		main()
{
	t_l		w;
	int		x = 10;
	int		y = 10;

	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 1000, 1000, "Coffee");
	w.img = mlx_new_image(w.mlx, 1000, 1000);
	w.addr = mlx_get_data_addr(w.img, &w.bit, &w.size, &w.endian);
	printf("bit = %i, Size = %i, Endian = %i\n", w.bit, w.size, w.endian);
	while (y < 500)
	{
		ft_put_pixel(w, x++, y, 0X002F4F4F);
		if (x >= 700)
		{
			y++;
			x = 10;
		}
	}
	mlx_put_image_to_window(w.mlx, w.win, w.img, 50, 50);
	mlx_loop(w.mlx);
	return (0);
}*/
