/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:12:51 by ltran             #+#    #+#             */
/*   Updated: 2017/07/31 23:28:21 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	trace_gril(t_coord *pt, t_xy *xy, t_xy *yx)
{
	while (xy != NULL)
	{
		trace(xy, pt);
		xy = xy->next;
	}
	while (yx != NULL)
	{
		trace(yx, pt);
		yx = yx->next;
	}
}

void	giv_zoom(t_coord *pt, int y)
{
	int		x;

	pt->xmax = (0 - pt->buf[0]) - (0 - pt->buf[0]);
	pt->xmin = pt->xmax;
	pt->ymax = (0 - pt->buf[0]) + (0 - pt->buf[0]);
	pt->ymin = pt->ymax;
	while (++y < pt->y + 1)
	{
		x = -1;
		while (++x < pt->x - 1 && y < pt->y)
		{
			if ((pt->xk = (x + 1) - pt->buf[(y * pt->x) + x + 1]) > pt->xmax)
				pt->xmax = pt->xk;
			if ((pt->yk = y - pt->buf[(y * pt->x) + x + 1]) > pt->ymax)
				pt->ymax = pt->yk;
			if (pt->xk < pt->xmin)
				pt->xmin = pt->xk;
			if (pt->yk < pt->ymin)
				pt->ymin = pt->yk;
		}
	}
	pt->zm = X / (2 * (pt->xmax - pt->xmin)) < Y / (2 * (pt->ymax - pt->ymin))
		? X / (2 * (pt->xmax - pt->xmin)) : Y / (2 * (pt->ymax - pt->ymin));
	pt->s_zm = pt->zm > 10 ? 5 : 1;
}

void	create_menu(t_coord *pt)
{
	mlx_string_put(pt->mlx, pt->win, 5, 5, rgb_to_hexa(pt), "ZOOM IN  : +");
	mlx_string_put(pt->mlx, pt->win, 5, 20, rgb_to_hexa(pt), "ZOOM OUT : -");
	mlx_string_put(pt->mlx, pt->win, 5, 45, rgb_to_hexa(pt), "RED   : ");
	mlx_string_put(pt->mlx, pt->win, 80, 45, rgb_to_hexa(pt), ft_itoa(pt->r));
	mlx_string_put(pt->mlx, pt->win, 5, 60, rgb_to_hexa(pt), "GREEN : ");
	mlx_string_put(pt->mlx, pt->win, 80, 60, rgb_to_hexa(pt), ft_itoa(pt->g));
	mlx_string_put(pt->mlx, pt->win, 5, 75, rgb_to_hexa(pt), "BLUE  : ");
	mlx_string_put(pt->mlx, pt->win, 80, 75, rgb_to_hexa(pt), ft_itoa(pt->b));
	mlx_string_put(pt->mlx, pt->win, 5, 90, rgb_to_hexa(pt), "R -|1| +|4|");
	mlx_string_put(pt->mlx, pt->win, 5, 105, rgb_to_hexa(pt), "G -|2| +|5|");
	mlx_string_put(pt->mlx, pt->win, 5, 120, rgb_to_hexa(pt), "B -|3| +|6|");
	mlx_string_put(pt->mlx, pt->win, 5, 1300, rgb_to_hexa(pt),
			"MOVEMENT <DIRECTIONAL ARROW>");
	mlx_string_put(pt->mlx, pt->win, 5, 1350, rgb_to_hexa(pt),
			"HEIGH -|/| +|*|");
}

void	start_window(t_coord *pt, t_xy *xy, t_xy *yx)
{
	if (pt->zm == 0)
	{
		pt->high = 1;
		pt->mlx = mlx_init();
		giv_zoom(pt, -1);
		pt->win = mlx_new_window(pt->mlx, X, Y, "Coffee");
		xy = lst_xy(pt, NULL, -1, 0);
		yx = lst_yx(pt, NULL);
		pt->dex = (-1 * pt->xmin) + (X - (pt->xmax - pt->xmin)) / 2;
		pt->dey = (-1 * pt->ymin) + (Y - (pt->ymax - pt->ymin)) / 2;
	}
	else
	{
		xy = lst_xy(pt, NULL, -1, 0);
		yx = lst_yx(pt, NULL);
	}
	pt->img = mlx_new_image(pt->mlx, X, Y);
	pt->adr = mlx_get_data_addr(pt->img, &(pt->bit), &(pt->line),
			&(pt->endian));
	trace_gril(pt, xy, yx);
	mlx_put_image_to_window(pt->mlx, pt->win, pt->img, 0, 0);
	create_menu(pt);
	mlx_hook(pt->win, 2, 3, ft_key, pt);
	mlx_loop(pt->mlx);
}
