/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 02:58:51 by ltran             #+#    #+#             */
/*   Updated: 2017/01/23 01:41:59 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "mlx.h"
#include "stdio.h"

int		ft_key(int keycode, void *param)
{
	printf("COUCOU ===> %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "cake");
	y = 30;
	x = 30;
	while ()
	mlx_pixel_put(mlx, win, x, y, 0X00FFCCCC, "42");
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
}
