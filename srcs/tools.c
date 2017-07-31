/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:42:55 by ltran             #+#    #+#             */
/*   Updated: 2017/07/31 23:20:48 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_key2(int keycode, void *param)
{
	if (keycode == 83)
		((t_coord*)param)->r -= 1;
	if (keycode == 84)
		((t_coord*)param)->g -= 1;
	if (keycode == 85)
		((t_coord*)param)->b -= 1;
	if (keycode == 86)
		((t_coord*)param)->r += 1;
	if (keycode == 87)
		((t_coord*)param)->g += 1;
	if (keycode == 88)
		((t_coord*)param)->b += 1;
	if (keycode == 75)
		((t_coord*)param)->high -= 1;
	if (keycode == 67)
		((t_coord*)param)->high += 1;
	mlx_destroy_image(((t_coord*)param)->mlx, ((t_coord*)param)->img);
	start_window((t_coord*)param, NULL, NULL);
	return (0);
}

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		((t_coord*)param)->dey -= 25;
	if (keycode == 123)
		((t_coord*)param)->dex -= 25;
	if (keycode == 124)
		((t_coord*)param)->dex += 25;
	if (keycode == 125)
		((t_coord*)param)->dey += 25;
	if (keycode == 69)
		((t_coord*)param)->zm += ((t_coord*)param)->s_zm;
	if (keycode == 78 && ((t_coord*)param)->zm - ((t_coord*)param)->s_zm > -1)
		((t_coord*)param)->zm -= ((t_coord*)param)->s_zm;
	return (ft_key2(keycode, param));
}

void	pixel_put(t_trace t, int color, t_coord *pt)
{
	int		i;

	i = pt->line * t.y1 + t.x1 * 4;
	pt->adr[i] = color & 0XFF;
	pt->adr[++i] = color >> 8 & 0XFF;
	pt->adr[++i] = color >> 16 & 0XFF;
}

int		rgb_to_hexa(t_coord *pt)
{
	if (pt->r < 0)
		pt->r = 255;
	if (pt->g < 0)
		pt->g = 255;
	if (pt->b < 0)
		pt->b = 255;
	if (pt->r > 255)
		pt->r = 0;
	if (pt->g > 255)
		pt->g = 0;
	if (pt->b > 255)
		pt->b = 0;
	return ((pt->r & 0XFF) << 16) + ((pt->g & 0XFF) << 8) + (pt->b & 0XFF);
}
