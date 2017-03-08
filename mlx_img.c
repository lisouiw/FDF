/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:47:20 by ltran             #+#    #+#             */
/*   Updated: 2017/03/08 01:45:26 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	ft_fill_img(char *addr, int x, int y, int color)
{
	mlx_pixel_put(mlx, win, x, y, color)
}

int		main()
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		*bit;
	int		*size;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Cae");
	img = mlx_new_image(mlx, 1000, 1000);
	addr = mlx_get_data_addr(img, bit, size, 0);
	ft_fill_img(addr, 1, 2,12);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
	return (0);
}
